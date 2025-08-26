import random
import time
import matplotlib.pyplot as plt

def linear_search(arr, target):
    for i in range(len(arr)):
        if arr[i] == target:
            return i
    return -1

sizes = [10, 50, 100, 500, 1000, 3000, 6000, 7000, 8000, 10000]
times = []

for n in sizes:
    arr = [random.randint(0, 10000) for _ in range(n)]
    target = arr[random.randint(0, n-1)]  # pick target from array

    start = time.time()
    for i in range(1000):
        linear_search(arr, target)
    end = time.time()

    elapsed = (end - start) / 1000
    times.append(elapsed)
    print(f"For input size {n}, time taken = {elapsed:.6f} sec")

plt.plot(sizes, times, marker='o')
plt.xlabel("Input Size (n)")
plt.ylabel("Time Taken (sec)")
plt.title("Linear Search Performance")
plt.grid(True)
plt.show()
