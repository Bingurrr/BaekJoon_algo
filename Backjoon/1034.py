"""
  지민이는 각 칸마다 램프가 들어있는 직사각형 모양의 탁자를 삼
  모든 램프는 켜져있거나 꺼져있음
  스위치를 누르면 그 열에 있는 램프의 상태가 바뀜 -> 열아래마다 스위치 있음
  켜져있는거는 꺼지고 꺼져있는거는 켜짐

  스위치를 k번 눌러 켜져있는 행을 최대로 하려고함

  입력 :
    첫째 줄  행의수 N 열의수 M
    둘째 줄 이후 : 램프의 상태 -> 1이 켜져있는거
    마지막 줄 : K
  출력 :
    켜져있는 행의 최댓값 
    켜져있는 행이란 그 행에 모든 램프가 켜져있어야함

  해결 :
    k가 홀수면 1,3,5,..k 만큼 열을 킬 수 있음
    k가 짝수이면 0,2,4...k만큼 열을 킬 수 있음
    k 가 주어졌을 때
    홀수 이면 0이 1개 3개 5개 ... k개 있는 것끼리 모아서 서로 0이 겹치는게 많을 수록 많이 킬 수 있다.
    -> 결국 똑같이 생겨야 킬 수 있다

"""

# 입력
N, M = map(int, input().split())
arr = [input() for _ in range(N)] # string상태
K = int(input())
if K > M :
  if K % 2 == 0 :
    if M % 2 == 0 :
      K = M
    else :
      K = M - 1
  else :
    if M % 2 == 0 :
      K = M - 1
    else :
      K = M
   
#print(K)
arr = sorted(arr, key=lambda x : x.count('0')) # 0이 작은것 부터 


max = 0
if K == 0:
  for i in range(N) :
    if arr[i].count('0') == 0 :
      max = max + 1
else :
  while K >= 0 :
    a = []
    for i in range(N) :
      if arr[i].count('0') != K or arr[i].count('0')%2 != K%2:
        continue
      else :
        a.append(arr[i])
    for j in a :
      if a.count(j) > max :
        max = a.count(j)
    K = K - 2

print(max)
