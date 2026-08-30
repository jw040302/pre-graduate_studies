def divide(first, second):
    if second == 0:
        raise ValueError("除数不能为0")
    return first / second


try:
    first_number = float(input("请输入被除数："))
    second_number = float(input("请输入除数："))
    result = divide(first_number, second_number)
except ValueError as error:
    print(f"输入或计算错误：{error}")
else:
    print(f"计算结果：{result}")
finally:
    print("程序执行结束")
