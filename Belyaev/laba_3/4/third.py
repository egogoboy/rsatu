import statistics

with open("3.txt", "r") as file:
    n = int(file.readline())
    sequence = [int(i) for i in file.readline()]

out = {
    'max': max(sequence),
    'min': min(sequence),
    'difference': max(sequence) - min(sequence),
    'average': statistics.mean(sequence),
    'median': statistics.median(sequence)
}

with open("3_out.txt", "w+") as out_file:
    for key, value in out.items():
        out_file.write(f"{key}: {value}\n")
