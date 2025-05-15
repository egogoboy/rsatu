import math

def get_simple_divisors():
    nums = [True] * 10000
    res = []

    for i in range(2, 10000):
        if (nums[i] == True):
            res.append(i)
            for j in range(i, 10000, i):
                nums[j] = False

    return res


print("Enter sequence with zero in the end: ")
x = int(input())

simple_divisors = get_simple_divisors()

while (x != 0):
    with open(f"Simple_divisors_of_{x}.txt", "w+") as file:
        for divisor in simple_divisors:
            if x % divisor == 0:
                file.write(str(divisor) + " ")
            if divisor > math.sqrt(x):
                break
    x = int(input())
