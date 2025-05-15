def get_difference(max_element: int, min_element: int):
    return max_element - min_element

def get_median(sequence: list): 
    sequence.sort()
    size = len(sequence)
    
    first = size // 2
    second = first - (size + 1) % 2
    return (sequence[first] + sequence[second]) / 2

max_element: int 
min_element: int
average: float
data = []

with open("1.txt", "r") as file:
    count_of_numbers = int(file.readline())
    x = int(file.readline())
    data.append(x)
    min_element = x
    max_element = x
    average = x
    for i in range(count_of_numbers - 1):
        x = int(file.readline())
        data.append(x)
        average += x
        if x < min_element:
            min_element = x
        if x > max_element:
            max_element = x

    average /= count_of_numbers

print("max element: ", max_element)
print("min element: ", min_element)
print("average value: ", average)
print("difference: ", get_difference(max_element, min_element))
print("median: ", get_median(data))
