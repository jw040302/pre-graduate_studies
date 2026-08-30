text = "  Python makes programming simple  "

clean_text = text.strip()
words = clean_text.split()

print(f"去除空格：{clean_text}")
print(f"替换内容：{clean_text.replace('simple', 'interesting')}")
print(f"查找位置：{clean_text.find('programming')}")
print(f"出现次数：{clean_text.count('m')}")
print(f"转为大写：{clean_text.upper()}")
print(f"拼接结果：{'-'.join(words)}")
