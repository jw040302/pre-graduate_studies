discount = 0.9


def calculate_price(price, quantity=1):
    return price * quantity * discount


def calculate(operation, first, second):
    return operation(first, second)


def average(*scores):
    return sum(scores) / len(scores)


def show_student(**student):
    for key, value in student.items():
        print(f"{key}：{value}")


numbers = [5, 2, 8, 1]
sorted_numbers = sorted(numbers, key=lambda number: number)

print(f"折后价格：{calculate_price(100, 2)}")
print(f"计算结果：{calculate(lambda first, second: first + second, 10, 20)}")
print(f"平均分：{average(80, 90, 85)}")
print(f"排序结果：{sorted_numbers}")

show_student(name="张三", age=20, major="计算机科学")
