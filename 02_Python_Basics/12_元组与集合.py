student = ("张三", 20, "计算机科学")
name, age, major = student

print(f"姓名：{name}")
print(f"年龄：{age}")
print(f"专业：{major}")

first_group = {"张三", "李四", "王五"}
second_group = {"王五", "赵六", "孙七"}

first_group.add("周八")
first_group.discard("李四")

print(f"并集：{first_group | second_group}")
print(f"交集：{first_group & second_group}")
print(f"差集：{first_group - second_group}")
