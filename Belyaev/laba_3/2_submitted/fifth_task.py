import math

x1, y1, rad1 = map(float, input("Enter coordinates and radius of first circle: ").split())
x2, y2, rad2 = map(float, input("Enter coordinates and radius of second circle: ").split())

distance = math.sqrt((x1 - x2)**2 + (y1 - y2)**2)

if (rad1 + rad2 >= distance) and (abs(rad1 - rad2) <= distance):
    print("Circles are intersect")
else:
    print("Circles aren't intersect")
