import statistics

sequence = []
with open("3.txt", "r") as file:
    n = int(file.readline())
    for i in range(n):
        sequence.append(int(file.readline()))

out = {
    'max': max(sequence),
    'min': min(sequence),
    'difference': max(sequence) - min(sequence),
    'average': statistics.mean(sequence),
    'median': statistics.median(sequence),
    'mode': statistics.mode(sequence)
}

with open("3_out.txt", "w+") as out_file:
    for key, value in out.items():
        out_file.write(f"{key}: {value}\n")
