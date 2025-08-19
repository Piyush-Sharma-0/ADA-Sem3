def selection_sort(a):
    n=len(a)
    for i in range(n-1):
        m=i
        for j in range(i+1,n):
            if a[j]<a[m]:
                m=j
        a[i],a[m]=a[m],a[i]
a=[5,2,9,1,5,6]
selection_sort(a)
print(a)
