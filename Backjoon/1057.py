arr = list(map(int, input().split()))
a = arr[1]
b = arr[2]
cnt = 0

while a != b :
  a = a-a//2
  b = b-b//2
  cnt = cnt + 1

print(cnt)
