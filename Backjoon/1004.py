"""

  첫줄 : 테스트 케이스 T
  출발점 도착점 x1, y1, x2, y2
  행성계의 개수
  중점과 반지름

  출력 : 행성 진입, 이탈 횟수
  
  행성 진입, 이탈 횟수 -> r > 중심과 점사이의 
  1 행성이 한점 포함
  2 행성이 두점 다 포함

  답은 1 - 2
"""

def distance(x1, y1, x2, y2, arr) :
  count = 0
  for i in range(len(arr)) :
    if (x1-arr[i][0])**2 + (y1-arr[i][1])**2 < arr[i][2]**2 and  (x2-arr[i][0])**2 + (y2-arr[i][1])**2 > arr[i][2]**2 :
      count = count + 1
    elif (x1-arr[i][0])**2 + (y1-arr[i][1])**2 > arr[i][2]**2 and  (x2-arr[i][0])**2 + (y2-arr[i][1])**2 < arr[i][2]**2 :
      count = count + 1
  return count

T = int(input())
for i in range(T) :
  x1, y1, x2, y2 = map(int, input().split())
  arr= []
  ret = 0
  N = int(input())
  for j in range(N) :
    arr.append(list(map(int, input().split())))
  ret = distance(x1,y1,x2,y2,arr)
  print(ret)
