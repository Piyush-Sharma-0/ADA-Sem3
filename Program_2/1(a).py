def bubble_sort(a):
    n=len(a)
    for i in range(n-1):
        for j in range(n-i-1):
            if a[j]>a[j+1]:
                a[j],a[j+1]=a[j+1],a[j]
a=[5,2,9,1,5,6]
bubble_sort(a)
print(a)
