"""
  A < B
  A <= x <= B를 만족하는 x 가 집합 s에 속하지 않는다
  
  입력 :
    첫째 줄 S의 크기 L
    둘째 줄 : 집합에 포함된 정수
    셋째 줄 : n
  출력 :
    첫째 줄 n에 포함하는 좋은 구간의 개수

    s = {둘째 줄 값} 
  풀이 :
    n을 포함하도록 하는 구간을 만들면됨
    a <= n <= b 은 (n - min) + (max - n) + (n - min) * (max - n) 를 하면 됨
"""
L = int(input())
s = map(int, input().split())
n = int(input())
s = sorted(s)

cnt = 0
min = 0
max = 0
if n in s :
  print(0)
elif n < s[0] :
  answer = (n - 1) + (s[0]-1 - n) + (n-1) * (s[0]-1-n)
  print(answer)
else :
  for i in s :
    if n > i :
      min = i +1 # 9
    if n < i :
      max = i-1 # 12
      break
  answer = (n - min) + (max - n) + (n - min) * (max - n)
  print(answer)




