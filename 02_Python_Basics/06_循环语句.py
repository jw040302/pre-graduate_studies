total = 0
number = 1

while number <= 100:
    total += number
    number += 1

print(f"1到100的和：{total}")

for number in range(1, 11):
    if number == 5:
        continue
    if number == 9:
        break
    print(number, end=" ")

print()
