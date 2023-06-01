n = int(input())

arr = map(int, input().split())

arr = sorted(arr)
print(arr[0], arr[n-1])