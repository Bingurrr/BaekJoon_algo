# 입력받기
n = int(input())
arr = [list(map(int, input().split())) for _ in range(n)]

num = [0,1,2,3,4,5,6,7,8,9]
a = [[10],[1],[6,2,4,8],[1,3,9,7],[6,4],[5],[6],[1,7,9,3],[6,8,4,2],[1,9]]
for i in range(n) :
  x = arr[i][0]%10
  y = arr[i][1]
  z = y%len(a[x])
  print(a[x][z])
