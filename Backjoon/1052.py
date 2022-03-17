import math
# 입력
N, K = map(int,input().split())

""" 
 N개의 물병을 가지고 있음
 처음에는 N개의 물통에 1L씩 물이 들어있음
 다른 장소로 물병을 옮기고 싶음 -> 한번옮길 수 있고 K개 옮길 수 있음 따라서 물병들을 합쳐야함

 K개가 넘지 않은 비어있는 물병을 만들고 싶음
 -> 같은 양의 물이 들어있는 물병을 두개 고르고 이를 합칠 수 있다

  내 생각
  2**x1 + 2**x2 + ... + 2**xk <= N+answer -> answer가 최솟이 되게해야함 N, K 는 주어짐
  따라서 2의 제곱의 합들이 최소가 되야햠
  answer = 2의 k승들의 합 - N
"""
if N == K :
  print(0)
else :
  a = N
  sum = 0
  tt = 0
  while K != 0 :
    if N == 0 : 
      break
    tt = 2**(int(math.log(N,2)))
    if N == 1 : tt = 1
    if K == 1 :
      tt = 2**(int(math.log(N,2))+1)
      if math.log(N,2) == int(math.log(N,2)) :
        tt = int(2**(math.log(N,2)))
    N = N - tt
    K = K - 1
    sum = sum + tt
  print(sum - a)
