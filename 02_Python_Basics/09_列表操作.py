fruits = ["苹果", "香蕉", "橙子", "葡萄"]

print(f"第一个水果：{fruits[0]}")
print(f"最后一个水果：{fruits[-1]}")
print(f"列表切片：{fruits[1:3]}")

fruits.append("西瓜")
fruits.insert(1, "梨")
fruits.extend(["桃子", "草莓"])
fruits.remove("香蕉")
removed_fruit = fruits.pop()

print(f"删除的水果：{removed_fruit}")
print(f"当前列表：{fruits}")
print(f"水果数量：{len(fruits)}")
print(f"是否包含苹果：{'苹果' in fruits}")
