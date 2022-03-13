from collections import deque

dx = [0,0,1,-1]
dy = [1,-1,0,0]

n = int(input())
for i in range(n) :
  arr = list(map(int, input().split()))

  t = []
  cnt = 1
  for j in range(arr[2]) :
    t.append(list(map(int, input().split())))
  dq = deque()
  dq.append(t[0])
  t.remove(t[0])
  while t != [] :
    xx, yy = dq.popleft()
    for k in range(4) :
      x = xx + dx[k]
      y = yy + dy[k]
      if x < 0 or y < 0 or x >= arr[0] or y >= arr[1] :
        continue
      if [x,y] in t :
        dq.append((x,y))
        t.remove([x,y])
    if dq :
      continue
    else :
      dq.append(t[0])
      t.remove(t[0])
      cnt = cnt + 1
  print(cnt)
