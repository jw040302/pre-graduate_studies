from ai_client import AIClient


def main():
    messages = [
        {"role": "system", "content": "你是一名简洁、友好的学习助手。"},
        {"role": "user", "content": "请给我三条保持学习动力的建议。"},
    ]

    try:
        client = AIClient.from_env()

        print("AI：", end="", flush=True)
        for content in client.stream_chat(messages):
            print(content, end="", flush=True)
        print()
    except RuntimeError as error:
        print(f"\n{error}")


if __name__ == "__main__":
    main()
