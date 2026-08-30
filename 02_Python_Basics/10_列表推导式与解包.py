scores = [85, 92, 67, 78, 95, 59]

passed_scores = [score for score in scores if score >= 60]
adjusted_scores = [min(score + 5, 100) for score in scores]

highest, *middle, lowest = sorted(scores, reverse=True)

print(f"及格成绩：{passed_scores}")
print(f"加分后的成绩：{adjusted_scores}")
print(f"最高分：{highest}")
print(f"中间成绩：{middle}")
print(f"最低分：{lowest}")
