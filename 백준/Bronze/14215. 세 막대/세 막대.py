arr = map(int, input().split())
arr = sorted(arr)
ans = arr[0] + arr[1] + min(arr[2], arr[0]+arr[1]-1)

print(ans)