class StudentNotFoundError(Exception):
    pass


def parse_age(text):
    age = int(text)

    if age < 1 or age > 150:
        raise ValueError("年龄必须在1到150之间")

    return age


def find_student(students, student_id):
    if student_id not in students:
        raise StudentNotFoundError("未找到该学生")

    return students[student_id]


students = {
    "001": {"name": "张三", "age": 20},
}

try:
    student_id = input("请输入新学生学号：").strip()

    if student_id in students:
        raise ValueError("学号已存在")

    name = input("请输入姓名：").strip()
    age = parse_age(input("请输入年龄："))

    students[student_id] = {"name": name, "age": age}

    query_id = input("请输入要查询的学号：").strip()
    student = find_student(students, query_id)
except ValueError as error:
    print(f"输入错误：{error}")
except StudentNotFoundError as error:
    print(f"查询失败：{error}")
else:
    print(f"查询结果：{student}")
finally:
    print("教务管理操作结束")
