num = int(input("Enter num: "))
prev = num

isIncreasing = True

while num != 0 and isIncreasing:
    num = int(input("Enter num: "))
    if (num <= prev and num != 0):
        isIncreasing = False
    prev = num
    
if isIncreasing:
    print("Sequence is increasing")
else:
    print("Sequence isn't increasing")
