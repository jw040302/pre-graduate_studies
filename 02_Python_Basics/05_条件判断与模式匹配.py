score = int(input("请输入考试成绩："))

if score >= 90:
    grade = "优秀"
elif score >= 80:
    grade = "良好"
elif score >= 60:
    grade = "及格"
else:
    grade = "不及格"

print(f"成绩等级：{grade}")

command = input("请输入命令（start、stop、help）：")

match command:
    case "start":
        print("程序开始运行")
    case "stop":
        print("程序停止运行")
    case "help":
        print("可用命令：start、stop、help")
    case _:
        print("未知命令")
