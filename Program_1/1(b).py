import random
import time
import matplotlib.pyplot as plt

def binary_search(arr, target):
    left = 0
    right = len(arr) - 1
    while left <= right:
        mid = (left + right) // 2
        if arr[mid] == target:
            return mid
        elif arr[mid] < target:
            left = mid + 1
        else:
            right = mid - 1
    return -1

sizes = [10, 50, 100, 500, 1000, 3000, 6000, 7000, 8000, 10000]
times = []

for n in sizes:
    arr = sorted([random.randint(0, 10000) for _ in range(n)])  # sorted for binary search
    target = random.randint(0, 10000)

    start = time.time()
    for i in range(1000):
        binary_search(arr, target)
    end = time.time()

    elapsed = (end - start) / 1000
    times.append(elapsed)
    print(f"For input size {n}, time taken = {elapsed:.6f} sec")

plt.plot(sizes, times, marker='o')
plt.xlabel("Input Size (n)")
plt.ylabel("Time Taken (sec)")
plt.title("Binary Search Performance")
plt.grid(True)
plt.show()
