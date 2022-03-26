N = int(input())
arr = list(map(int, input().split()))

arr = sorted(arr)
time = 0
for i in range(len(arr)) :
  time += (len(arr) - i) * arr[i]
print(time)
