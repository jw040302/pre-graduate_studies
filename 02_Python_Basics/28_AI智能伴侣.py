import json
import os
from pathlib import Path

from ai_client import AIClient


class AICompanion:
    def __init__(self, client: AIClient, companion_name: str, user_name: str, memory_file: Path):
        self.client = client
        self.companion_name = companion_name
        self.user_name = user_name
        self.memory_file = memory_file
        self.messages = [self._system_message()]
        self.load_memory()

    def _system_message(self) -> dict[str, str]:
        return {
            "role": "system",
            "content": (
                f"你叫{self.companion_name}，是{self.user_name}的AI智能伴侣。"
                "你友好、真诚、耐心，能够陪伴聊天，也能帮助制定学习计划和复盘。"
                "回答应自然简洁，不编造事实。遇到医疗、法律、财务或紧急安全问题时，"
                "明确说明能力边界，并建议寻求合适的专业帮助。"
            ),
        }

    def load_memory(self):
        if not self.memory_file.exists():
            return

        try:
            data = json.loads(self.memory_file.read_text(encoding="utf-8"))
            history = data.get("messages", [])

            for message in history:
                if not isinstance(message, dict):
                    continue

                role = message.get("role")
                content = message.get("content")

                if role in {"user", "assistant"} and isinstance(content, str):
                    self.messages.append({"role": role, "content": content})

            self._trim_history()
        except (OSError, json.JSONDecodeError, AttributeError):
            print("历史记忆读取失败，将开始新的对话。")

    def save_memory(self):
        data = {
            "companion_name": self.companion_name,
            "user_name": self.user_name,
            "messages": self.messages[1:],
        }

        try:
            self.memory_file.write_text(
                json.dumps(data, ensure_ascii=False, indent=2),
                encoding="utf-8",
            )
        except OSError as error:
            print(f"记忆保存失败：{error}")

    def _trim_history(self, maximum: int = 20):
        history = self.messages[1:]

        if len(history) > maximum:
            history = history[-maximum:]

        self.messages = [self._system_message(), *history]

    def clear_memory(self):
        self.messages = [self._system_message()]
        self.save_memory()
        print("对话记忆已清空。")

    def show_history(self):
        if len(self.messages) == 1:
            print("暂无历史对话。")
            return

        for message in self.messages[1:]:
            speaker = self.user_name if message["role"] == "user" else self.companion_name
            print(f"{speaker}：{message['content']}")

    def reply(self, user_input: str):
        self.messages.append({"role": "user", "content": user_input})
        answer_parts = []

        print(f"{self.companion_name}：", end="", flush=True)

        try:
            for content in self.client.stream_chat(self.messages):
                answer_parts.append(content)
                print(content, end="", flush=True)
            print()
        except RuntimeError:
            self.messages.pop()
            raise

        answer = "".join(answer_parts).strip()

        if answer:
            self.messages.append({"role": "assistant", "content": answer})
            self._trim_history()
            self.save_memory()

    def run(self):
        print(f"{self.companion_name}：你好，{self.user_name}！输入 /help 查看可用命令。")

        while True:
            try:
                user_input = input(f"{self.user_name}：").strip()
            except (EOFError, KeyboardInterrupt):
                print(f"\n{self.companion_name}：下次再见！")
                return

            if not user_input:
                continue

            if user_input == "/exit":
                print(f"{self.companion_name}：下次再见！")
                return

            if user_input == "/clear":
                self.clear_memory()
                continue

            if user_input == "/history":
                self.show_history()
                continue

            if user_input == "/help":
                print("/history 查看历史  /clear 清空记忆  /exit 退出")
                continue

            try:
                self.reply(user_input)
            except RuntimeError as error:
                print(f"请求失败：{error}")


def main():
    companion_name = os.getenv("AI_COMPANION_NAME", "小星").strip() or "小星"
    user_name = os.getenv("AI_USER_NAME", "朋友").strip() or "朋友"
    memory_path = os.getenv("AI_COMPANION_MEMORY", "ai_companion_memory.json")

    try:
        client = AIClient.from_env()
        companion = AICompanion(client, companion_name, user_name, Path(memory_path))
        companion.run()
    except RuntimeError as error:
        print(error)


if __name__ == "__main__":
    main()
