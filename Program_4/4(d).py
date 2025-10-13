import time
import matplotlib.pyplot as plt

def fib_bottom_up(n):
    if n == 0:
        print(0, end=" ")
        return
    if n == 1:
        print(0, 1, end=" ")
        return

    dp = [0] * (n + 1)
    dp[1] = 0
    dp[2] = 1

    for i in range(3, n + 1):
        dp[i] = dp[i - 1] + dp[i - 2]

    #Print the sequence
    #for i in range(1, n + 1):
        #print(dp[i], end=" ")


sizes = [10, 100, 500, 1000]
times = []

for n in sizes:
    start = time.perf_counter()
    fib_bottom_up(n)
    end = time.perf_counter()
    elapsed = end - start
    times.append(elapsed)
    print(f"For input size {n}, time taken = {elapsed:.6f} sec")

plt.plot(sizes, times, marker='o', label="Recursive Sequence Generator")
plt.xlabel("Input Size (n)")
plt.ylabel("Time Taken (seconds)")
plt.title("Bottom-Up Fibonacci Sequence Generator Performance")
plt.legend()
plt.grid(True)
plt.show()
