start=[1,3,0,5,3,5,6,8,8,2,12]
finish=[5,5,6,7,9,9,10,11,12,14,16]
main=[]
for i in range(len(start)):
    main.append([start[i],finish[i]])
main.sort(key=lambda x: x[1])

count=1
j=0

doing=[]

for i in range(1,len(main)):
    if main[i][0]>main[j][1]:
        count+=1
        j+=1
        doing.append(main[i])
print(count)
print(doing)