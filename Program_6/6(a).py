start=[1,2,4,6,5,8]
finish=[3,5,6,7,8,9]
main=[]
for i in range(len(start)):
    main.append([start[i],finish[i]])
main.sort(key=lambda x: x[1])

count=1
j=0

doing=[list(main[0])]

for i in range(1,len(main)):
    if main[i][0]>main[j][1]:
        count+=1
        j+=1
        doing.append(main[i])
print(count)
print(doing)