import time
import matplotlib.pyplot as plt

def fibonachi_by_recursive(n, x=0, y=1):
    if n == 0:
        return
    if n == 1:
        # print(x, end=" ")
        return
    # print(x, y, end=" ")
    x = x + y
    y = y + x
    fibonachi_by_recursive(n - 2, x, y)

sizes = [10, 100, 500, 1000]
times = []

for n in sizes:
    start = time.perf_counter()
    fibonachi_by_recursive(n)
    end = time.perf_counter()
    elapsed = end - start
    times.append(elapsed)
    print(f"For input size {n}, time taken = {elapsed:.6f} sec")

plt.plot(sizes, times, marker='o', label="Recursive Sequence Generator")
plt.xlabel("Input Size (n)")
plt.ylabel("Time Taken (seconds)")
plt.title("Recursive Fibonacci Sequence Generator Performance")
plt.legend()
plt.grid(True)
plt.show()
