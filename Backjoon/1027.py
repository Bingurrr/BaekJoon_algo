## 1027

"""
  세준시에는 고층빌딩이 많음
  i 번쨰 빌딩은 (i,0)부터 (i,높이)의 선분으로 나타낼 수 있음

  고층 빌딩 A에서 다른 고층 빌딩 B가 볼 수 있는 빌딩이 되려면
  두 지붕을 잇는 선분이 A,B를 제외하고 지나가거나 접하면 안됨

  입력 :
    첫째 줄 : 빌딩 수 N
    둘째 줄 : 빌딩의 높이들
  출력 :
    가장 많이 보이는 빌딩의 수
  
  해결 :
    i 번째에 있는 건물이 오른쪽 있는 건물을 볼려면 -> 이전 기울기의 최댓값 보다 커야한다
    i 번째에 있는 건물이 왼쪽 있는 건물을 볼려면 -> 이전 기울기의 최솟값보다 작아야한다.
"""
# 입력
N = int(input())
buildings = list(map(int, input().split()))

answer = 0

def see_buildings(num, arr) :
  left = num
  right = num
  angle = 0
  ret = 0
  dist = 1 # 두 건물사이 거리
  min = -1000000001
  max = 1000000000
  # 왼쪽 시야
  while left != 0 : 
    left = left - 1
    angle = (arr[num] - arr[left])/(num - left)
    if angle < max :
      ret = ret + 1
      max = angle
  # 오른쪽 시야
  dist = 1
  while right != len(arr)-1 :
    right = right + 1
    angle = (arr[right]-arr[num])/(right - num)
    if angle > min :
      ret = ret + 1
      min = angle
  return ret

for i in range(N) :
  a = see_buildings(i, buildings)
  if a > answer :
    answer = a

print(answer)

