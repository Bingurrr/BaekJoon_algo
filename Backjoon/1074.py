N, r, c = map(int, input().split())

k = 1
cnt = 0
x, y = 2**(N-k), 2**(N-k)
while N > 0 :
  a, b = 2**(N-k), 2**(N-k)
  #print("aaa",x,y)
  # 2사분면
  if r <= x-1  and c <= y-1:
    cnt += 0
    x = x - a//2
    y = y - b//2 
    N -= 1
    #print("2사분면", cnt)
  # 1사분면
  elif r <= x-1 and c > y-1 : 
    cnt += a*b
    x = x - a//2
    y = y + b//2
    N -=1
   # print("1사분면", cnt)
  # 3사분면
  elif r > x-1 and c <= y -1 :
    cnt += 2*a*b
    x = x + a//2
    y = y - b//2 
    N -= 1
    #print("3사분면", cnt)
  # 4사분면
  else :
    cnt += 3*a*b
    x = x + a//2 
    y = y + b//2 
    N -= 1
    #print(x,y)
    #print("4사분면", cnt)

print(cnt)
