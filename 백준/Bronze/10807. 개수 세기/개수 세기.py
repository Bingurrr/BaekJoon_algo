n = input()
arr = list(map(int, input().split()))
k = int(input())
ans = 0

for i in arr :
    if i == k :
        ans += 1
        
print(ans)