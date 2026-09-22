import json
import os
from collections.abc import Iterator
from urllib.error import HTTPError, URLError
from urllib.request import Request, urlopen


class AIClient:
    def __init__(self, endpoint: str, api_key: str, model: str, timeout: int = 60):
        self.endpoint = endpoint
        self.api_key = api_key
        self.model = model
        self.timeout = timeout

    @classmethod
    def from_env(cls):
        endpoint = os.getenv("AI_API_URL", "").strip()
        api_key = os.getenv("AI_API_KEY", "").strip()
        model = os.getenv("AI_MODEL", "").strip()

        missing = []

        if not endpoint:
            missing.append("AI_API_URL")
        if not api_key:
            missing.append("AI_API_KEY")
        if not model:
            missing.append("AI_MODEL")

        if missing:
            names = "、".join(missing)
            raise RuntimeError(f"请先配置环境变量：{names}")

        return cls(endpoint, api_key, model)

    def _create_request(self, payload: dict) -> Request:
        body = json.dumps(payload, ensure_ascii=False).encode("utf-8")
        headers = {
            "Authorization": f"Bearer {self.api_key}",
            "Content-Type": "application/json",
        }
        return Request(self.endpoint, data=body, headers=headers, method="POST")

    def _raise_request_error(self, error: Exception):
        if isinstance(error, HTTPError):
            detail = error.read().decode("utf-8", errors="replace")
            raise RuntimeError(f"AI服务返回错误（{error.code}）：{detail}") from error

        if isinstance(error, URLError):
            raise RuntimeError(f"无法连接AI服务：{error.reason}") from error

        raise RuntimeError(f"AI请求失败：{error}") from error

    def chat(self, messages: list[dict[str, str]], temperature: float = 0.7) -> str:
        payload = {
            "model": self.model,
            "messages": messages,
            "temperature": temperature,
        }
        request = self._create_request(payload)

        try:
            with urlopen(request, timeout=self.timeout) as response:
                data = json.loads(response.read().decode("utf-8"))
        except (HTTPError, URLError, TimeoutError, json.JSONDecodeError) as error:
            self._raise_request_error(error)

        try:
            return data["choices"][0]["message"]["content"]
        except (KeyError, IndexError, TypeError) as error:
            raise RuntimeError("AI服务返回了无法识别的数据格式") from error

    def stream_chat(
        self,
        messages: list[dict[str, str]],
        temperature: float = 0.7,
    ) -> Iterator[str]:
        payload = {
            "model": self.model,
            "messages": messages,
            "temperature": temperature,
            "stream": True,
        }
        request = self._create_request(payload)

        try:
            with urlopen(request, timeout=self.timeout) as response:
                for raw_line in response:
                    line = raw_line.decode("utf-8", errors="replace").strip()

                    if not line.startswith("data:"):
                        continue

                    data_text = line[5:].strip()

                    if data_text == "[DONE]":
                        return

                    try:
                        data = json.loads(data_text)
                        content = data["choices"][0]["delta"].get("content")
                    except (json.JSONDecodeError, KeyError, IndexError, TypeError):
                        continue

                    if content:
                        yield content
        except (HTTPError, URLError, TimeoutError) as error:
            self._raise_request_error(error)
