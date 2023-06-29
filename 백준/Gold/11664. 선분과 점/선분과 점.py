import sys
x1, y1, z1, x2, y2, z2, x3, y3, z3 = map(int, sys.stdin.readline().split())

def distance(x1, y1, z1, x2, y2, z2):                             
    return ((x2-x1)**2 + (y2-y1)**2 + (z2-z1)**2) ** (1/2)


minlen = 1e9
l1 = distance(x1, y1, z1, x3, y3, z3)
l2 = distance(x2, y2, z2, x3, y3, z3)

while True:
    mx = (x1 + x2) / 2
    my = (y1 + y2) / 2
    mz = (z1 + z2) / 2
    l3 = distance(mx, my, mz, x3, y3, z3)        
    if abs(minlen - l3) <= 1e-6:
        print('{:.10f}'.format(l3))
        break
    minlen = min(l3, minlen)
    if l1 < l2:              						# [시작점과 C 사이의 거리]가 [끝점과 C 사이의 거리]보다 작을때, 끝점을 시작점쪽으로 당기기
        x2, y2, z2 = mx, my, mz
        l2 = l3
    else:
        x1, y1, z1 = mx, my, mz
        l1 = l3