import math

x, y, d, t = map(int,input().split())
d1 = (x**2+y**2)**0.5

n = max(d1//d,1)
d2 = min(abs(d1-d*n)+t*n, d1-d*n+d+t*n) 
d3 = max(math.ceil(d1/d),2)*t

print(min(d1,d2,d3))