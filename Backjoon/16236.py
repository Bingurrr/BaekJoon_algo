## 백준 16236
## https://www.acmicpc.net/problem/16236

from collections import deque

# 입력받기
n = int(input())
arr = [list(map(int, input().split())) for _ in range(n)]


# 상어 초기위치 찾기
for i in range(n) :
  for j in range(n) :
    if arr[i][j] == 9 :
      shark_x = i
      shark_y = j
      arr[i][j] = 0

# 문제 풀기위한 초기값
shark_size = 2
grow = 2
ret = 0

dx = (0, 0,-1, 1)
dy = (1,-1,0,0)


"""
  BFS를 구성하는 법 
  1. 시작위치를 queue에 넣는다
  2. queue에서 하나를 꺼내고 그 자식노드를 넣는다. 단 넣을 때 조건 생각
  3. queue가 빌때까지 반복한다.
"""

def BFS(shark_x, shark_y, shark_size):
  visited[shark_x][shark_y] = 1 # 현재 위치를 1로 설정
  dq = deque()
  dq.append((shark_x,shark_y))
  
  while dq :
    x, y = dq.popleft()
    for i in range(4) :
      new_x = dx[i] + x
      new_y = dy[i] + y
      if new_x < 0 or new_y < 0 or new_x >= n or new_y >=n :
        continue
      if (visited[new_x][new_y] != 0) or (arr[new_x][new_y] > shark_size):
        continue
      visited[new_x][new_y] = visited[x][y] +1 # 자식노드는 부모노드 이동거리 + 1
      dq.append((new_x,new_y)) # 자식노드 queue에 삽입


while True :
    visited = [[0] * n for _ in range(n)]
    BFS(shark_x, shark_y, shark_size)
    x = 0
    y = 0
    min_distance = 400
    for i in range(n) :
      for j in range(n) :
        if visited[i][j] != 0 and arr[i][j] < shark_size and arr[i][j] > 0 :
          if min_distance > visited[i][j] -1 :
            min_distance = visited[i][j] -1
            x = i
            y = j
    
    if min_distance != 400 :
      ret += min_distance
      grow = grow -1
      shark_x = x
      shark_y = y
      if grow == 0:
        shark_size = shark_size +1
        grow = shark_size
      arr[shark_x][shark_y] = 0
    else :
      break

print(ret)
