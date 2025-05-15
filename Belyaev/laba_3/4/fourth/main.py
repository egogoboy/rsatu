import statistics
import matplotlib.pyplot as pyplot
import matplotlib

matplotlib.use('TkAgg')

def calculate_statistic(data):
    res = {
        'average': statistics.mean(data),
        'median': statistics.median(data),
        'stdev': statistics.stdev(data) if len(data) > 1 else 0,
        'variance': statistics.variance(data) if len(data) > 1 else 0,
        'difference': max(data) - min(data)
    }
    return res

def visualize(data, stats):
    pyplot.figure(figsize=(10, 4))

    pyplot.scatter(data, [0] * len(data), alpha=0.7, label='Data')

    pyplot.axvline(stats['average'], color='r', linestyle='--', label=f'Average ({stats["average"]:.2f})')
    pyplot.axvline(stats['median'], color='g', linestyle=':', label=f'Median ({stats["median"]:.2f})')

    lower_bound = stats['average'] - stats['stdev']
    upper_bound = stats['average'] + stats['stdev']
    pyplot.axvspan(lower_bound, upper_bound, color='gray', alpha=0.2,
             label=f'±1 σ ({lower_bound:.2f}–{upper_bound:.2f})')

    pyplot.title('Statistics')
    pyplot.yticks([])
    pyplot.legend()
    pyplot.grid(True, linestyle='--', alpha=0.5)
    pyplot.tight_layout()
    pyplot.show()

with open('input.txt', 'r') as f:
    line = f.readline()
    data = [float(x) for x in line.split()]

    stats = calculate_statistic(data)

    print("Result:")
    for key, value in stats.items():
        print(f"{key:>8}: {value:.2f}")

    visualize(data, stats)
