import sys

n = int(sys.stdin.readline())
tmp = [[] for _ in range(101)]
dic = [{} for i in range(101)]
cnt = 0

for i in range(n):
    num = 0
    m = str(sys.stdin.readline()).rstrip('\n')

    for j in m:
        if j not in dic[i]:
            dic[i][j] = str(num)
            num += 1
        tmp[i] += dic[i][j]

for i in range(n):
    for j in range(i + 1, n):
        if tmp[i] == tmp[j]:
            cnt += 1
print(cnt)