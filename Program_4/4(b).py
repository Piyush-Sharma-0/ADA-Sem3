import time
import matplotlib.pyplot as plt

def fibonacchi_by_iterative(n):
    x=0
    y=1
    n=n-2
    #print(x,y,end=" ")
    for i in range(n):
        if(i%2==0):
            x=x+y
            #print(x,end=" ")
        else:
            y=y+x
            #print(y,end=" ")

sizes = [10, 100, 500, 1000]
times = []

for n in sizes:
    start = time.perf_counter()
    fibonacchi_by_iterative(n)
    end = time.perf_counter()
    elapsed = end - start
    times.append(elapsed)
    print(f"For input size {n}, time taken = {elapsed:.6f} sec")

plt.plot(sizes, times, marker='o', label="Recursive Sequence Generator")
plt.xlabel("Input Size (n)")
plt.ylabel("Time Taken (seconds)")
plt.title("Iterative Fibonacci Sequence Generator Performance")
plt.legend()
plt.grid(True)
plt.show()
