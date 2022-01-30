def count(arr,val):
    a1=a2=-1
    lt=[]
    for i in range(len(arr)):
        if arr[i] == val:
            a1=i
            break

    for i in range(len(arr)-1,0,-1):
        if arr[i] == val:
            a2 = i
            break

    return a2-a1+1





lt=[]
n=int(input("Total size?"))
for i in range(n):
    val=int(input("Value??"))
    lt.append(val)

ele=int(input("Value to be searched?"))

ans1=count( lt, ele )
print(f'Total count of {ele} is {ans1}')