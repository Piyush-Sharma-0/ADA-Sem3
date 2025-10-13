import time
import matplotlib.pyplot as plt

def fib_upto(n):
    memo = [0] * (n + 1)
    if n >= 1:
        memo[1] = 0
    if n >= 2:
        memo[2] = 1

    for i in range(3, n + 1):
        memo[i] = memo[i - 1] + memo[i - 2]

    #for i in range(1, n + 1):
        #print(memo[i], end=" ")

sizes = [10, 100, 500, 1000]
times = []

for n in sizes:
    start = time.perf_counter()
    fib_upto(n)
    end = time.perf_counter()
    elapsed = end - start
    times.append(elapsed)
    print(f"For input size {n}, time taken = {elapsed:.6f} sec")

plt.plot(sizes, times, marker='o', label="Recursive Sequence Generator")
plt.xlabel("Input Size (n)")
plt.ylabel("Time Taken (seconds)")
plt.title("Top-down Fibonacci Sequence Generator Performance")
plt.legend()
plt.grid(True)
plt.show()

