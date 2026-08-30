import math
import random
from datetime import date


def calculate_circle_area(radius):
    return math.pi * radius ** 2


if __name__ == "__main__":
    random.seed(42)

    print(f"圆的面积：{calculate_circle_area(5):.2f}")
    print(f"随机数：{random.randint(1, 100)}")
    print(f"今天的日期：{date.today()}")
