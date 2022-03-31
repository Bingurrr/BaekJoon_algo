"""
  N N 크기의 집이 있다
  각각의 칸은 (r,c)로 나타낼 수 있다
  파이브는 2개의 연속된 칸을 차지하는 크기


  꼭 빈칸이어야 하는곳은 색으로 표시되어있다.
  벽은 1로 되어있다.
  
  직관적으로 문제를 해석했고 BFS를 이용하여 푼 결과 시간초과가 나오게 됨
  DP나 DFS를 
"""
import sys
from collections import deque
input = sys.stdin.readline

N = int(input())
arr = [list(map(int, input().split())) for _ in range(N)]

pos = (0,1,0,0)
move1 = [(0,1,0,1),(1,1,0,1)] 
move2 = [(1,0,1,0),(1,1,1,0)]
move3 = [(1,1,1,1),(0,1,1,1),(1,0,1,1)]

def bfs() :
  cnt = 0
  dq = deque()
  dq.append(pos)
  while dq :
    x1,y1, x2,y2 = dq.popleft()
    if y1 == y2 :
      for i in move2 :
        new_x1 = x1 + i[0]
        new_y1 = y1 + i[1]
        new_x2 = x2 + i[2]
        new_y2 = y2 + i[3]
        if new_x1 >= N or new_y1 >= N or arr[new_x1][new_y1] == 1 or ((arr[new_x1-1][new_y1] == 1 or arr[new_x1][new_y1-1] == 1) and i[0] == 1 and i[1] == 1) :
          continue
        if new_x1 == N-1 and new_y1 == N-1 :
          cnt += 1
          continue
        else :  
          dq.append((new_x1,new_y1,new_x2,new_y2))
    elif x1 == x2 :
      for i in move1 : 
        new_x1 = x1 + i[0]
        new_y1 = y1 + i[1]
        new_x2 = x2 + i[2]
        new_y2 = y2 + i[3]
        if new_x1 >= N or new_y1 >= N or arr[new_x1][new_y1] == 1 or ((arr[new_x1-1][new_y1] == 1 or arr[new_x1][new_y1-1] == 1)and i[0] == 1 and i[1] == 1):
          continue
        if new_x1 == N-1 and new_y1 == N-1 :
          cnt += 1
          continue
        else :
          dq.append((new_x1,new_y1,new_x2,new_y2))
    else :
      for i in move3 : 
        new_x1 = x1 + i[0]
        new_y1 = y1 + i[1]
        new_x2 = x2 + i[2]
        new_y2 = y2 + i[3]
        if new_x1 >= N or new_y1 >= N or arr[new_x1][new_y1] == 1 or ((arr[new_x1-1][new_y1] == 1 or arr[new_x1][new_y1-1] == 1)and i[0] == 1 and i[1] == 1):
          continue
        if new_x1 == N-1 and new_y1 == N-1 :
          cnt += 1
          continue
        else :
          dq.append((new_x1,new_y1,new_x2,new_y2))    
  return cnt  
      
ans = bfs()
print(ans)
