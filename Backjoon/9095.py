T = int(input())

def sum124(n) :
  if n == 1 :
    return 1
  elif n == 2 :
    return 2 
  elif n == 3 :
    return 4 
  else :
    return sum124(n-1) + sum124(n-2) + sum124(n-3)

for _ in range(T) :
  n = int(input())
  print(sum124(n))
