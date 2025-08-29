import random
import time
import matplotlib.pyplot as plt

def insertion_sort(arr):
    n = len(arr)
    for i in range(1, n):
        k = arr[i]
        j = i - 1
        while j >= 0 and arr[j] > k:
            arr[j+1] = arr[j]
            j -= 1
        arr[j+1] = k

sizes = [10, 50, 100, 500, 1000, 3000, 6000, 7000, 8000]
times = []

for n in sizes:
    arr = [random.randint(0, 10000) for _ in range(n)]
    start = time.time()
    insertion_sort(arr)
    end = time.time()
    print(f"For input size {n} time taken = {end-start}")
    times.append(end-start)

plt.plot(sizes, times, marker='o')
plt.xlabel("Input size (n)")
plt.ylabel("Time taken (seconds)")
plt.title("Insertion Sort Time Complexity")
plt.show()
