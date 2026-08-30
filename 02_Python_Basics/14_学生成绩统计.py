student_scores = {
    "张三": 85,
    "李四": 92,
    "王五": 76,
    "赵六": 58,
}

average_score = sum(student_scores.values()) / len(student_scores)
top_student = max(student_scores, key=student_scores.get)
passed_students = {
    name: score
    for name, score in student_scores.items()
    if score >= 60
}

print(f"平均分：{average_score:.2f}")
print(f"最高分学生：{top_student}，{student_scores[top_student]}分")
print(f"及格学生：{passed_students}")
