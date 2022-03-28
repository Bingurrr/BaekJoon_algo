import sys
input = sys.stdin.readline
 
n, m = map(int, input().split())
arr = list(map(int, input().split()))
s = [0]   
 
sum = 0    
for i in arr:    
    sum += i
    s.append(sum)
 
for i in range(m):
    a, b = map(int, input().split())
    print(s[b] - s[a-1])
