import matplotlib.pyplot as plt

# Read log file
names = []
times = []

with open("dijkstra_times.txt", "r") as f:
    for line in f:
        parts = line.strip().split()
        names.append(parts[0])
        times.append(float(parts[1]))

# Plot bar chart
plt.bar(names, times)
plt.title("Dijkstra Performance Comparison")
plt.xlabel("Algorithm Version")
plt.ylabel("Time (seconds)")
plt.grid(axis='y')
plt.show()

# Optional: wipe file after plotting
open("dijkstra_times.txt", "w").close()
