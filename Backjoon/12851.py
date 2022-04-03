from collections import deque
N, K = map(int, input().split())


move = (1, -1)
dq = deque()
min = 10000000
cnt = 0
dq.append((N,0))
visited = [100000 for _ in range(101001)]
if N == K :
  print(0)
  print(1)
else :
  while dq :
    x,y = dq.popleft()
    if x > K :
      new_x = x -1
      new_y = y + 1
      if new_y > visited[new_x]:
        continue
      else :
        visited[new_x] = new_y
        if new_x == K :
          if min > new_y :
            min = new_y
            cnt = 1
          else :
            cnt += 1
        else :    
          dq.append((new_x,new_y))
    else :
      for i in range(2) :
        new_x = x + move[i]
        new_y = y + 1
        if new_y > visited[new_x]:
          continue
        else :
          visited[new_x] = new_y
          if new_x == K :
            if min > new_y :
              min = new_y
              cnt = 1
            else :
              cnt += 1
          else :
            dq.append((new_x, new_y))
      if abs(2*x - K) > abs(x-K) or 2*x > 100000 :
        continue
      else :
        new_x = x *2
        new_y = y + 1
        if new_y > visited[new_x]:
          continue
        else :
          visited[new_x] = new_y
          if new_x == K :
            if min > new_y :
              min = new_y
              cnt = 1
            else :
              cnt += 1
          else :
            dq.append((new_x, new_y))
      
  print(min)
  print(cnt)


