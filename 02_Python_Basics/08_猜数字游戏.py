import random

answer = random.randint(1, 100)
attempts = 5

while attempts > 0:
    guess = int(input("请输入1到100之间的数字："))
    attempts -= 1

    if guess == answer:
        print("恭喜你，猜对了！")
        break
    if guess < answer:
        print("猜小了")
    else:
        print("猜大了")

    print(f"剩余次数：{attempts}")
else:
    print(f"次数用完了，正确答案是{answer}")
