from collections import deque
import sys

def bfs(x, y):
    q = deque([])
    q.append((x,y,K))
    visited = [[[0 for i in range(31)] for i in range(W)] for i in range(H)]
    while q:
        x, y, cnt = q.popleft()

        if x == H - 1 and y == W - 1:
            return visited[x][y][cnt]

        for i in range(4):
            nx, ny = x + dx[i], y + dy[i]

            if 0 <= nx < H and 0 <= ny < W and not arr[nx][ny] and not visited[nx][ny][cnt]:
                q.append((nx, ny, cnt))
                visited[nx][ny][cnt] = visited[x][y][cnt] + 1

        if cnt > 0:
            for i in range(8):
                nx, ny = x + dxx[i], y + dyy[i]
                if 0 <= nx < H and 0 <= ny < W and not arr[nx][ny] and not visited[nx][ny][cnt-1]:
                    q.append((nx, ny, cnt-1))
                    visited[nx][ny][cnt-1] = visited[x][y][cnt] + 1
    return -1


K = int(input())
W, H = map(int, input().split())
arr = [list(map(int, sys.stdin.readline().split())) for _ in range(H)]
dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]
dxx = [-2, -2, -1, -1, 1, 1, 2, 2]
dyy = [-1, 1, -2, 2, -2, 2, -1, 1]



print(bfs(0,0))