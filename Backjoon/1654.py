"""
  박성원 N 개의 랜선을 만들어얗암
  이미 오영식은 K개의 랜선을 가지고 있음
  그러나 K개의 랜선의 길이는 제각각이다.

  박성원은 N개의 같은 길이의 랜선으로 만들어야 한다.
  K개의 랜선을 잘라서 만들어야 한다

  이미 자른 랜선은 붙일 수 없다.

  N개보다 많이 만드는것도 N개를 만드는 것으로 취급

  최대 랜선의 길이를 구하시오


  입력 
  첫줄 K, N
  둘째 ~ K
  K 줄에 거쳐 이미 가지고 있는 각각의 랜선의 길이
"""
"""
  N개를 만들어야함
  길이가 X인 K개에서 N개를 만들어야함
  근데 x * N의 최대가 되는 값
  test case
  11 
  802 //x + 743 //x + 457//x + 546//x == 11

  완전탐색할 경우 시간초과 걸림
  이진 탐색
"""
# 입력
arr= list(map(int, input().split()))
num = []

max = 0

for i in range(arr[0]) :
  num.append(int(input()))
  if max < num[i] :
    max = num[i]

left = 1
right = max
while left <= right :
  a = 0
  x = (left + right)//2
  if x == 0 :
    right = left
    break
  for i in num :
    a = a + i//x
  if a < arr[1] :
    right = x - 1
  elif a >= arr[1] :
    left = x + 1

print(right)

