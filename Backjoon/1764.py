import sys


N, M = map(int, sys.stdin.readline().split())
a = [sys.stdin.readline().strip() for i in range(N)]
b = [sys.stdin.readline().strip() for i in range(M)]

answer = list(set(a) & set(b))
print(len(answer))
for i in sorted(answer) :
  print(i)
