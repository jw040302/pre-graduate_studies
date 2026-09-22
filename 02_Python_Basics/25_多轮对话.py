from ai_client import AIClient


def main():
    messages = [
        {
            "role": "system",
            "content": "你是一名Python学习助手，请结合此前对话回答问题。",
        }
    ]

    try:
        client = AIClient.from_env()

        while True:
            question = input("你：").strip()

            if question.lower() in {"exit", "quit", "退出"}:
                break
            if not question:
                continue

            messages.append({"role": "user", "content": question})
            answer = client.chat(messages)
            messages.append({"role": "assistant", "content": answer})

            print(f"AI：{answer}")
    except RuntimeError as error:
        print(error)


if __name__ == "__main__":
    main()
