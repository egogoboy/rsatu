angle = float(input("Enter angle: "))

SECONDS_IN_DEGREE = 120
seconds = int(SECONDS_IN_DEGREE * angle)

hours = int(seconds // 3600)
seconds -= hours * 3600
minutes = int(seconds // 60)
seconds -= minutes * 60

print(angle, "->", hours, ":", minutes, ":", seconds)
