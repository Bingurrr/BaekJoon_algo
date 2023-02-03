import math
import sys
# 입력
N, K = map(int,input().split())

# 물병을 구입할 필요가 없을 때
if N <= K :
  print(0)
else :
  input_N = N
  sum = 0 # 2의 거듭제곱의 합으로 나타내줘야함
  tmp = 0 # 남은 N값으로 만들 수 있는 2의 거듭제곱중 가장 큰 값
  while K != 0 :
    if N == 0 : 
      break
    tmp = 2**(int(math.log(N,2)))
    if K == 1 :
      tmp = 2**(int(math.log(N,2))+1)
      if math.log(N,2) == int(math.log(N,2)) :
        tmp = int(2**(math.log(N,2)))
    N = N - tmp
    K = K - 1
    sum = sum + tmp 
    
  print(sum - input_N)