N, M = map(int, input().split())
site = dict()
pwd = []
answer = []
for _ in range(N) :
  a, b =input().split()
  site[a] = b
for _ in range(M) :
  pwd.append(input())
for i in pwd :
  print(site[i])
