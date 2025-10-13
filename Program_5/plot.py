import matplotlib.pyplot as plt

times = {}
with open("knapsack_times.txt", "r") as f:
    for line in f:
        parts = line.strip().split()
        time_val = float(parts[-1])
        name = " ".join(parts[:-1])
        times[name] = time_val

names = list(times.keys())
values = [times[n] for n in names]

plt.bar(names, values, color=['blue','green','red'])
plt.ylabel("Time (seconds)")
plt.title("Knapsack Approaches Time Comparison")
plt.xticks(rotation=20)
plt.grid(axis='y')
plt.show()
