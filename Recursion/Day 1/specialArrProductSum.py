def productSum(arr,depth):
    sum = 0
    for i in arr:
        if type(i) == type([]):
            sum += productSum(i,depth+1)
        else:
            sum += i
    return sum*depth

if __name__ == "__main__":
    prSum = productSum( arr=[ 5, 2, [ 7,-1 ], 3, [ 6, [ -13,8 ], 4 ]], depth=1)
    print(f"Product Sum: {prSum}")