# 입력받기
n = int(input())
for i in range(n) :
  a, b = map(int, input().split())
  c = b-a
  answer = 1
  while a!=b :
    answer = answer*b
    b = b-1
  if c == 0 :
    print(answer)
    continue
  while c != 1 :
    answer = answer//c
    c = c -1
  print(answer)
