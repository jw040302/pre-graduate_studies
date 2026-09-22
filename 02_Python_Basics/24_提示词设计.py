from ai_client import AIClient


def build_messages(topic: str, level: str) -> list[dict[str, str]]:
    return [
        {
            "role": "system",
            "content": (
                "你是一名编程课程设计师。回答应准确、简洁，"
                "使用中文，并给出一个可以直接运行的短小示例。"
            ),
        },
        {
            "role": "user",
            "content": (
                f"请为{level}学习者讲解“{topic}”。"
                "依次给出概念、示例和一道练习题。"
            ),
        },
    ]


def main():
    try:
        client = AIClient.from_env()
        messages = build_messages("Python列表推导式", "入门")
        print(client.chat(messages, temperature=0.4))
    except RuntimeError as error:
        print(error)


if __name__ == "__main__":
    main()
