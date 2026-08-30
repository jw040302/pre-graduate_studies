def calculate_average(scores: list[float]) -> float:
    return sum(scores) / len(scores)


def find_student(student_id: int, students: dict[int, str]) -> str | None:
    return students.get(student_id)


student_scores: list[float] = [85.0, 92.5, 78.0]
students: dict[int, str] = {1: "张三", 2: "李四"}

print(f"平均分：{calculate_average(student_scores):.2f}")
print(f"查询结果：{find_student(1, students)}")
