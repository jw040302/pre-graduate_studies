class Person:
    species = "人类"

    def __init__(self, name, age):
        self.name = name
        self.age = age

    def celebrate_birthday(self):
        self.age += 1

    def __str__(self):
        return f"姓名：{self.name}，年龄：{self.age}，类别：{self.species}"


person = Person("张三", 20)
person.celebrate_birthday()

print(person)
print(f"已创建的类：{person.__class__.__name__}")
