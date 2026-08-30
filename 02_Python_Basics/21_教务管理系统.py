class Student:
    def __init__(self, student_id, name, age):
        self.student_id = student_id
        self.name = name
        self.age = age

    def __str__(self):
        return f"学号：{self.student_id}，姓名：{self.name}，年龄：{self.age}"


class StudentManager:
    def __init__(self):
        self.students = []

    def add_student(self, student):
        self.students.append(student)

    def find_student(self, student_id):
        for student in self.students:
            if student.student_id == student_id:
                return student
        return None

    def update_student(self, student_id, name, age):
        student = self.find_student(student_id)
        if student is None:
            return False

        student.name = name
        student.age = age
        return True

    def remove_student(self, student_id):
        student = self.find_student(student_id)
        if student is None:
            return False

        self.students.remove(student)
        return True

    def show_all(self):
        for student in self.students:
            print(student)


manager = StudentManager()
manager.add_student(Student("001", "张三", 20))
manager.add_student(Student("002", "李四", 21))

manager.update_student("002", "李四", 22)

student = manager.find_student("001")
if student is not None:
    print(f"查询结果：{student}")

manager.remove_student("001")
manager.show_all()
