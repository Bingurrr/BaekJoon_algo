arr = [i for i in range(1,10000)]

def d(n) :
  sum = 0
  while n != 0 :
    sum += n % 10
    n = n // 10
  return sum


for i in arr :
  while i < 10000 :
    i = i + d(i)
    if i in arr :
      arr.remove(i)
    else :
      break

for j in arr :
  print(j)
