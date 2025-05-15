size = int(input("Enter size of sequence: "))
mass = []

num = None
for i in range(size):
    num = int(input("Enter num: "))
    mass.append(num)

out= set(filter(lambda x: mass.count(x) > 1, mass))

print("Repeated elements:", out)
