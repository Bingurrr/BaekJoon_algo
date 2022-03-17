"""
  입력 첫째 줄 : 끈ㅊㅎ어진 줄 갯수 N, 브랜드 갯수
  둘째 줄 6개가 들어있는 패키지 가격, 낱개 가격

"""
N, M = map(int, input().split())
a = [] # 패키지가격
b = [] # 낱개 가격
for i in range(M) :
  x, y = map(int, input().split())
  if y*6 < x :
    a.append(y*6)
    b.append(y)
    continue
  a.append(x)
  b.append(y)

a = sorted(a)
b = sorted(b)

answer = a[0]*(N//6) + b[0]*(N%6)
if a[0] < b[0]*(N%6) :
  answer = a[0]*(N//6) + a[0]
if a[0] == 0 or b[0] == 0 :
  answer = 0

print(answer)
