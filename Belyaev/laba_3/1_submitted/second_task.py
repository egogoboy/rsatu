n = int(input("Enter three-digit number: "))

while (n < 100 or n > 999):
    print(n, "is not three-digit number")
    n = int(input("Enter three-digit number: "))

reverse_n = 0
sum = 0

while (n != 0):
    reverse_n = reverse_n * 10 + n % 10
    sum += n % 10
    n //= 10

print("Reversed number:", reverse_n)
print("Sum of digits of number:", sum)
