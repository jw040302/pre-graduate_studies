name = input("请输入姓名：")
age = int(input("请输入年龄："))
hobby = input("请输入爱好：")

introduction = "大家好，我叫" + name + "。"

print(introduction)
print(f"我今年{age}岁，喜欢{hobby}。")
print("明年我就%d岁了。" % (age + 1))
