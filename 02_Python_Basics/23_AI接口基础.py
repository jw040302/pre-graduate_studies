from ai_client import AIClient


def main():
    try:
        client = AIClient.from_env()
        answer = client.chat(
            [
                {"role": "system", "content": "你是一名耐心的编程助教。"},
                {"role": "user", "content": "请用一句话解释什么是Python函数。"},
            ]
        )
        print(answer)
    except RuntimeError as error:
        print(error)


if __name__ == "__main__":
    main()
