n, m = map(int,input().split())
a = n
ans = 1
while n != m and n != a - m :
  ans *= n
  n = n - 1
if n == m :
  while a - m !=  1 :
    ans //= (a-m)
    a -= 1
else :
  while m !=  1 :
    ans //= m
    m -= 1
print(ans)
