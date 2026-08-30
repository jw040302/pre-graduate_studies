first = 15
second = 4

print(f"加法：{first + second}")
print(f"减法：{first - second}")
print(f"乘法：{first * second}")
print(f"除法：{first / second}")
print(f"整除：{first // second}")
print(f"取余：{first % second}")
print(f"幂运算：{first ** 2}")

number = 10
number += 5
number *= 2
print(f"赋值运算结果：{number}")

print(f"first大于second：{first > second}")
print(f"两个条件都成立：{first > 10 and second < 10}")
print(f"至少一个条件成立：{first < 10 or second < 10}")
print(f"条件取反：{not first == second}")
