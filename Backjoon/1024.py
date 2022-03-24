N, L = map(int, input().split())
num = -1
while True :
  a = N/L - (L-1)/2
  b = int(N/L - (L-1)/2)
  if a < 0 or L > 100:
    print(-1)
    break
  if a == b :
    num = b
    break
  else :
    L = L + 1
if num != -1 :
  for _ in range(L) :
    print(num, end = ' ')
    num = num + 1
