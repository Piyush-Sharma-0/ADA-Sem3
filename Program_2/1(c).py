def insertion_sort(a):
    n=len(a)
    for i in range(1,n):
        k=a[i]
        j=i-1
        while j>=0 and a[j]>k:
            a[j+1]=a[j]
            j-=1
        a[j+1]=k
a=[5,2,9,1,5,6]
insertion_sort(a)
print(a)
