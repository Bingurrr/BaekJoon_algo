T = int(input())
for _ in range(T) :
  N = int(input()) 
  clothes = dict()
  for i in range(N) :
    a,b = input().split()
    if clothes.get(b) == None :
      clothes[b] = set()
    clothes[b].add(a)
  count = 1
  for k in clothes.keys():
    count *= len(clothes[k]) + 1
  print(count-1)
