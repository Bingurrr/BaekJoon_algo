import sys

n = int(sys.stdin.readline())
data = []
for i in range(n):
    data.append(int(sys.stdin.readline()))
data.sort()

cnt, ans = 0, 0
start = 0

for end in range(len(data)):
    cnt += 1
    while data[end] - data[start] > 4:
        start += 1
        cnt -= 1

    ans = max(ans, cnt)

if ans > 5:
    ans = 5
print(5 - ans)