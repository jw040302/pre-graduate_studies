def factorial(number):
    if number <= 1:
        return 1
    return number * factorial(number - 1)


def sum_numbers(number):
    if number <= 0:
        return 0
    return number + sum_numbers(number - 1)


print(f"5的阶乘：{factorial(5)}")
print(f"1到100的和：{sum_numbers(100)}")
