import random
import time
import matplotlib.pyplot as plt

def partition(arr, low, high):
    pivot = arr[high]
    i = low - 1
    for j in range(low, high):
        if arr[j] <= pivot:
            i += 1
            arr[i], arr[j] = arr[j], arr[i]
    arr[i+1], arr[high] = arr[high], arr[i+1]
    return i+1

def quick_sort(arr, low, high):
    if low < high:
        pi = partition(arr, low, high)
        quick_sort(arr, low, pi-1)
        quick_sort(arr, pi+1, high)

sizes = [10, 50, 100, 500, 1000, 3000, 6000, 7000, 8000]
times = []

for n in sizes:
    arr = [random.randint(0, 10000) for _ in range(n)]
    start = time.time()
    quick_sort(arr, 0, n-1)
    end = time.time()
    print(f"For input size {n} time taken = {end-start}")
    times.append(end-start)

plt.plot(sizes, times, marker='o')
plt.xlabel("Input size (n)")
plt.ylabel("Time taken (seconds)")
plt.title("Quick Sort Time Complexity")
plt.show()
