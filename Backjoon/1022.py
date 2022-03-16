a = list(map(int, input().split()))
# 가장긴 숫자의 길이

m = -5000
for x in a :
  if m < abs(x) :
    m = abs(x)
y1 = a[0] + m
x1 = a[1] + m
y2 = a[2] + m
x2 = a[3] + m

## 1. 가장 큰 값에 따라서 회오리를 만든다.

tt = [[1]*(x2-x1+1) for i in range(y2-y1+1)]

#print(tt)

num = (2*m+1) * (2*m+1)
x = 2*m
y = 2*m
edge = 2*m

for i in range(m) : 
  while x - 1 != 2*m - edge -1  :
    if y <= y2 and y >= y1 and x <= x2 and x >= x1 :
      tt[y-y1][x-x1] = num
    num = num -1
    x = x - 1
  while  y - 1 != 2*m - edge - 1:
    if y <= y2 and y >= y1 and x <= x2 and x >= x1 :
      tt[y-y1][x-x1] = num
    num = num -1
    y = y - 1
  while x + 1 != edge + 1 :
    if y <= y2 and y >= y1 and x <= x2 and x >= x1 :
      tt[y-y1][x-x1] = num
    num = num -1
    x = x + 1
  edge = edge - 1
  while y + 1 != edge + 1 :
    if y <= y2 and y >= y1 and x <= x2 and x >= x1 :
      tt[y-y1][x-x1] = num
    num = num -1
    y = y + 1

## 2. 구간을 자르고 출력
l = len(str(max(map(max, tt))))

for i in range(len(tt)) :
  for j in range(len(tt[0])) :
    if len(str(tt[i][j])) != l :
      print(" "*(l-len(str(tt[i][j]))-1), tt[i][j], end = " ")
    else :
      print(tt[i][j], end = " ")
  print()
      









