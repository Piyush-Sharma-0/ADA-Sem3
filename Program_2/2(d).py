import random
import time
import matplotlib.pyplot as plt

def merge_sort(arr):
    if len(arr) > 1:
        mid = len(arr)//2
        L = arr[:mid]
        R = arr[mid:]
        merge_sort(L)
        merge_sort(R)
        i = j = k = 0
        while i < len(L) and j < len(R):
            if L[i] <= R[j]:
                arr[k] = L[i]
                i += 1
            else:
                arr[k] = R[j]
                j += 1
            k += 1
        while i < len(L):
            arr[k] = L[i]
            i += 1
            k += 1
        while j < len(R):
            arr[k] = R[j]
            j += 1
            k += 1

sizes = [10, 50, 100, 500, 1000, 3000, 6000, 7000, 8000]
times = []

for n in sizes:
    arr = [random.randint(0, 10000) for _ in range(n)]
    start = time.time()
    merge_sort(arr)
    end = time.time()
    print(f"For input size {n} time taken = {end-start}")
    times.append(end-start)

plt.plot(sizes, times, marker='o')
plt.xlabel("Input size (n)")
plt.ylabel("Time taken (seconds)")
plt.title("Merge Sort Time Complexity")
plt.show()
