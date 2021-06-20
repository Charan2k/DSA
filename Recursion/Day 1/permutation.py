permList = []
retList = []
def perms(arr,n):
    permList.append(arr)
    if(n==0): return 
    for i in range(n):
        for j in range(i+1, n):
            arr[i],arr[j] = arr[j], arr[i]
            perms(arr,n-1)
            print(permList[0])      
            arr[i],arr[j] = arr[j], arr[i]


if __name__ == "__main__":
    n = int(input("Size: "))
    arr = input().split()
    arr = [int(x) for x in arr]
    perms(arr,n)