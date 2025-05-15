from array import array

def triangleSquare(sides: array):
    return float(0.5 * sides[0] * sides[1])

sides = array('f', [0, 0, 0])

sides[0] = float(input("Enter first side: "))
sides[1] = float(input("Enter second side: "))
sides[2] = float(input("Enter third side: "))

sorted(sides)

if sides[0]**2 + sides[1]**2 == sides[2]**2:
    print("Square of triangle =", triangleSquare(sides))
else:
    print("Triangle with same sides is not exist")
