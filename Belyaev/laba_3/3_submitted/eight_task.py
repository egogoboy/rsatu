mass = []

num = int(input("Enter num: "))

while num != 0:
    mass.append(num)
    num = int(input("Enter num: "))

k = int(input("Enter k: "))

out = list(filter(lambda x: x <= k, mass))

print("Input array:",mass)
print("Output array:", out)
