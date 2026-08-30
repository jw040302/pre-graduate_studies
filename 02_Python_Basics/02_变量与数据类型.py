name = "张三"
age = 20
height = 1.75
is_student = True
address = None

first = 10
second = 20
first, second = second, first

print(f"姓名：{name}")
print(f"年龄：{age}")
print(f"身高：{height}")
print(f"是否为学生：{is_student}")
print(f"交换结果：first={first}, second={second}")

print(type(name))
print(type(age))
print(type(height))
print(type(is_student))
print(type(address))
