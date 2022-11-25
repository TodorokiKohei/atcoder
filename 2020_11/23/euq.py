a = 201
b = 78
while a % b != 0:
    tmp = a % b
    a = b
    b = tmp
print(b)