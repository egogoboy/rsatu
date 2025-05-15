n = int(input("Enter count of numbers: "))

max_num = -1

for i in range(n):
    x = int(input("Enter number: "))
    if x > max_num:
        max_num = x

print("Max number: ", max_num)
