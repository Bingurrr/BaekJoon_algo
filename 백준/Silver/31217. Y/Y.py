import sys
input = sys.stdin.readline

R = 10**9 + 7
ans = 0
n, m = map(int, input().split())

dic = dict()
for _ in range(m) :
    u, v = map(int, input().split())
    if u not in dic :
        dic[u] = 1
    else :
        dic[u] += 1
    
    if v not in dic :
        dic[v] = 1
    else :
        dic[v] += 1

for k in dic.values() :
    if k >= 3 :
        ans += int((k*(k-1)*(k-2)/6)%R)


print(ans % R)

