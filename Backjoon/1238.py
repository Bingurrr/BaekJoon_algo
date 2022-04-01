from collections import deque
N, M, X = map(int,input().split())
arr= []
for i in range(M) :
  a = list(map(int, input().split()))
  arr.append(a)
go = [0 for _ in range(N+1)]
back = [0 for _ in range(N+1)]
dq = deque()
dq.append(X)
while dq :
  x = dq.popleft()
  for a in arr :
      if x == a[1] :
        if go[a[0]] == 0 :
          go[a[0]] = a[2] + go[x]
          dq.append(a[0])
        if go[x] + a[2] < go[a[0]] :
          go[a[0]] = go[x] + a[2]
          dq.append(a[0])

back = [0 for _ in range(N+1)]
dq2 = deque()
dq2.append(X)
while dq2 :
  y = dq2.popleft()
  for a in arr :
      if y == a[0] :
        if back[a[1]] == 0 :
          back[a[1]] = a[2] + back[y]
          dq2.append(a[1])
        elif back[y] + a[2] < back[a[1]] :
          back[a[1]] = back[y] + a[2]
          dq2.append(a[1])

ans = 0
go[X] = 0
back[X] = 0
for i in range(len(go)) :
  if ans < go[i] + back[i] :
    ans = go[i] + back[i]
print(ans)    
