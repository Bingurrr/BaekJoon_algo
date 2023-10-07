# This is a sample Python script.

# Press Shift+F10 to execute it or replace it with your code.
# Press Double Shift to search everywhere for classes, files, tool windows, actions, and settings.

import sys

input = sys.stdin.readline
# print = sys.stdout.write

n = int(input())

arr = [[0]*n for i in range(n)]
visit = [[0]*n for i in range(n)]
origin = []

ans = 0

def sol(r,c, likes) :
    ret = -1
    if r + 1 < n and arr[r + 1][c] in likes:
        ret += 1
    if r - 1 >= 0 and arr[r - 1][c] in likes:
        ret += 1
    if c + 1 < n and arr[r][c + 1] in likes :
        ret += 1
    if c - 1 >= 0 and arr[r][c - 1] in likes:
        ret += 1
    return ret


for i in range(n*n) :
    input_arr = list(map(int, input().split()))
    visit = [[0] * n for i in range(n)]
    x = input_arr[0]
    likes = set(input_arr[1:])
    target = []
    max_val = 0
    cnt = 0
    # condition 1
    for r in range(n) :
        for c in range(n) :
            if arr[r][c] == 0 :
                if r+1 < n and arr[r+1][c] in likes :
                    visit[r][c] += 1
                if r-1 >= 0 and arr[r-1][c] in likes :
                    visit[r][c] += 1
                if c+1 < n and arr[r][c+1] in likes :
                    visit[r][c] += 1
                if c-1 >= 0 and arr[r][c-1] in likes :
                    visit[r][c] += 1
                if visit[r][c] > max_val :
                    max_val = visit[r][c]
                    cnt = 0
                    target = []
                    target.append([r,c])
                elif visit[r][c] == max_val :
                    target.append([r, c])
                    cnt += 1
    if cnt == 0 :
        arr[target[0][0]][target[0][1]] = x
        # print('condition 1')
        origin.append((x, likes, target[0][0], target[0][1]))
        continue
    # print(arr)
    # print(target)
    # condition 2
    target2 = []
    for r, c in target :
        # print('222')
        if arr[r][c] == 0:
            if r + 1 < n and arr[r + 1][c] == 0:
                visit[r][c] += 1
            if r - 1 >= 0 and arr[r - 1][c] == 0:
                visit[r][c] += 1
            if c + 1 < n and arr[r][c + 1] == 0:
                visit[r][c] += 1
            if c - 1 >= 0 and arr[r][c - 1] == 0:
                visit[r][c] += 1
            if visit[r][c] > max_val:
                max_val = visit[r][c]
                cnt = 0
                target2 = []
                target2.append([r, c])
            elif visit[r][c] == max_val:
                target2.append((r, c))
                cnt += 1
        continue
    # print('aaa')
    if cnt == 0 :
        arr[target2[0][0]][target2[0][1]] = x
        # print('condition 2: ')
        origin.append((x, likes, target2[0][0], target2[0][1]))
        continue

    # condition 3
    arr[target2[0][0]][target2[0][1]] = x
    # print('condition 3: ')
    origin.append((x, likes, target2[0][0], target2[0][1]))

# print(arr)

for x, likes,r, c in origin :
    y = sol(r,c, likes)
    # print(r,c,likes, int(10**y))
    ans += int(10**y)


print(ans)