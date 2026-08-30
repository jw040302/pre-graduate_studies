def calculate_total(price, quantity):
    """计算商品总价。"""
    return price * quantity


def create_student(name, age):
    return name, age


def show_order(name, price, quantity):
    total = calculate_total(price, quantity)
    print(f"{name}购买了{quantity}件商品，总价为{total:.2f}元")


student_name, student_age = create_student("张三", 20)
print(f"学生：{student_name}，年龄：{student_age}")

show_order(student_name, 19.9, 3)
