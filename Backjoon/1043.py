from collections import deque
N, M = map(int, input().split())

num = list(map(int, input().split()))

if len(num) == 1 :
  for _ in range(M) :
    a = input()
  print(M)
else :
  true_people = set(num[1:len(num)])
  arr = []
  for i in range(M) :
    a = list(map(int, input().split()))
    arr.append(a[1:])
  #print(arr)
  nothing = True
  while nothing :
    nothing = False
    for x in arr :
      if set(x) & true_people != set() :
        true_people = set(x) | true_people
        arr.remove(x)
        nothing = True
        #print(true_people)
  print(len(arr))
    



    
