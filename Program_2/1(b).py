import random
import time
import matplotlib.pyplot as plt

def selection_sort(arr):
    n = len(arr)
    for i in range(n-1):
        m = i
        for j in range(i+1, n):
            if arr[j] < arr[m]:
                m = j
        arr[i], arr[m] = arr[m], arr[i]

sizes = [10, 50, 100, 500, 1000, 3000, 6000, 7000, 8000]
times = []

for n in sizes:
    arr = [random.randint(0, 10000) for _ in range(n)]
    start = time.time()
    selection_sort(arr)
    end = time.time()
    print(f"For input size {n} time taken = {end-start}")
    times.append(end-start)

plt.plot(sizes, times, marker='o')
plt.xlabel("Input size (n)")
plt.ylabel("Time taken (seconds)")
plt.title("Selection Sort Time Complexity")
plt.show()
