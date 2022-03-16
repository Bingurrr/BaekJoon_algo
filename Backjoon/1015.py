# 입력받기
n = int(input())
arr = list(map(int, input().split()))
answer = [0 for _ in range(n)]
p = [[arr[i], i] for i in range(n)]

p = sorted(p, key=lambda x:x[0])

num=0
for j in range(n) :
  answer[p[j][1]] = num
  num = num+1

for k in range(len(answer)) :
  print(answer[k], end = " ")
