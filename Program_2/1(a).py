import random,time
import matplotlib.pyplot as plt

def bubble_sort(arr,n):
    for i in range(n-1):
        for j in range(n-i-1):
            if arr[j]>arr[j+1]:
                arr[j],arr[j+1]=arr[j+1],arr[j]

sizes=[10,50,100,500,1000,3000,6000,7000,8000]
times=[]

for n in sizes:
    arr=[random.randint(0,9999) for _ in range(n)]
    start=time.time()
    bubble_sort(arr,n)
    end=time.time() 
    times.append(end-start)
    print(f"For input size {n} time taken = {end-start}")

plt.plot(sizes,times,marker='o')
plt.xlabel("Input Size")
plt.ylabel("Time (seconds)")
plt.title("Bubble Sort Time Complexity")
plt.show()
