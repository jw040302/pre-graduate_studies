import json

from ai_client import AIClient


def remove_code_fence(text: str) -> str:
    lines = text.strip().splitlines()

    if lines and lines[0].startswith("```"):
        lines = lines[1:]
    if lines and lines[-1].strip() == "```":
        lines = lines[:-1]

    return "\n".join(lines).strip()


def main():
    messages = [
        {
            "role": "system",
            "content": "你只返回合法JSON，不要使用Markdown代码块。",
        },
        {
            "role": "user",
            "content": (
                "生成一份三天Python复习计划。返回对象必须包含title和days，"
                "days中的每项包含day、topic和task。"
            ),
        },
    ]

    try:
        client = AIClient.from_env()
        content = client.chat(messages, temperature=0.2)
        plan = json.loads(remove_code_fence(content))

        print(plan["title"])
        for item in plan["days"]:
            print(f"第{item['day']}天：{item['topic']} - {item['task']}")
    except (RuntimeError, json.JSONDecodeError, KeyError, TypeError) as error:
        print(f"结构化结果处理失败：{error}")


if __name__ == "__main__":
    main()
