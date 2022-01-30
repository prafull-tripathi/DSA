def high_binary_search(arr,val):
    low = 0
    pos = -1
    high = len( arr ) - 1
    if low>=high:
        return low
    while low <= high:
        mid = (low + high) // 2
        if arr[mid] == val:
            pos = mid
            low = mid + 1
        elif arr[mid] > val:
            high = mid - 1
        else:
            low = mid + 1
    return pos


def low_binary_search(arr,val):
    low = 0
    pos = -1
    high = len( arr ) - 1
    if low>=high:
        return low
    while low <= high:
        mid = (low + high) // 2
        if arr[mid] == val:
            pos = mid
            high = mid - 1
        elif arr[mid] > val:
            high = mid - 1
        else:
            low = mid + 1
    return pos


lt=[]
n=int(input("Total size?"))
for i in range(n):
    val=int(input("Value??"))
    lt.append(val)

ele=int(input("Value to be searched?"))

ans1=low_binary_search( lt, ele )
ans2=high_binary_search( lt, ele )
print(f'Total count of {ele} is {ans2-ans1+1}')