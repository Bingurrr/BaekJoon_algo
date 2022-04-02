
## 내 풀이 
"""
  이게 5 1 2 
       5 1 3 이렇게도 입력이 되는것 같음
       고려를 못했음
  다른 사람 풀이를 참고했는데 다익스트라를 쓰는것 같음
"""
import sys

input = sys.stdin.readline
from collections import deque
N = int(input())
M = int(input())
bus =[]
for _ in range (M) :
  bus.append(list(map(int, input().split())))

A, B = map(int, input().split())
cost = [0 for _ in range(N+1)]

dq = deque()
dq.append(B)
while dq :
  x = dq.popleft()
  for a in bus :
    if x == a[1] :
      if cost[a[0]] == 0:
        cost[a[0]] = a[2] + cost[x]
        dq.append(a[0])
      elif cost[a[0]] > a[2] + cost[x] :
        cost[a[0]] = a[2] + cost[x]
        dq.append(a[0])

print(cost[A])




