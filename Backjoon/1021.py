N, M = map(int, input().split())

arr = list(map(int,input().split()))
num = [i for i in range(1,N+1)]
cnt = 0
for i in range(M) :
  index = num.index(arr[i])
  a = len(num)
  num = num[index+1:] + num[:index]
  #print(num)
  if a - 1 - index < index :
    cnt += a  - index
  else :
    cnt += index

print(cnt)
