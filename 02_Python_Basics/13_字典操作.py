student = {
    "name": "张三",
    "age": 20,
    "major": "计算机科学",
}

print(f"姓名：{student['name']}")
print(f"成绩：{student.get('score', '暂无')}")

student["age"] = 21
student["score"] = 88
removed_major = student.pop("major")

print(f"删除的专业：{removed_major}")

for key, value in student.items():
    print(f"{key}：{value}")
