N, M = map(int, input().split())
arr = []
for i in range(N) :
  s = input()
  a = []
  for j in range(M) :
    a.append(int(s[j]))
  arr.append(a)

answer = 1

if N > M : 
  min = M
else :
  min = N
ttt = False
while min != 0 :
  for i in range(N-min) :
    for j in range(M-min) :
      if arr[i][j] == arr[i+min][j+min] and arr[i][j] == arr[i+min][j] and arr[i][j] == arr[i][j+min] :
        answer = (min+1)*(min+1)
        ttt = True
  min = min -1
  if ttt :
    break
        

print(answer)
