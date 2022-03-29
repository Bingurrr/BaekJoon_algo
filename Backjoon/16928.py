"""
  주사위 이동할 수 있는거리 1~6
  을 이용하여 bfs를 만듦
  사다리와 뱀이 있는 곳에는 이동할 수 있는곳을 변경해줌

"""

from collections import deque
N, M = map(int, input().split())
a = []
b = []
arr = [i for i in range(101)]
visited = [0 for _ in range(101)]
visited[100] = 999999999
for _ in range(N) : 
  x, y = map(int, input().split())
  a.append((x,y))
  arr[x] = y
for _ in range(M) : 
  x, y = map(int, input().split())
  b.append((x,y))
  arr[x] = y

move = (1,2,3,4,5,6)

def bfs() :
  dq = deque()
  pos = 1
  arr[1] = 1
  dq.append(arr[1])
  while dq :
    pos = dq.popleft()
    for i in range(6) :
      new_pos = pos + move[i]
      if new_pos >= 100 :
        if visited[100] > visited[pos] + 1 :
          visited[100] = visited[pos] + 1
      elif visited[new_pos] != 0 :
        continue
      elif visited[new_pos] == 0 and arr[new_pos] == 0:
        visited[new_pos] = visited[pos] + 1
        dq.append(new_pos)
      elif arr[new_pos] != 0 :
        new_pos = arr[new_pos]
        if visited[new_pos] == 0 :
          visited[new_pos] = visited[pos] + 1
          dq.append(new_pos)
bfs()
print(visited[100])
