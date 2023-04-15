n, m = map(int, input().split())

str = set()
ans = 0

for i in range(n) :
    k = input()
    str.add(k)

for i in range(m) : 
    k = input()
    if k in str :
        ans += 1

print(ans)