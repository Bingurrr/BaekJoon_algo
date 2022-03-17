n = int(input())

def is_han(num) :
  if len(str(num)) <= 2 :
    return True
  #print(num)
  d = int(num[1]) - int(num[0])
  #print(num[1], num[0])
  for i in range(len(num)-1) :
    if int(num[i]) + d != int(num[i+1]) :
      return False
  return True

answer = 0
for i in range(1, n+1) :
  if is_han(str(i)) :
    answer = answer + 1
print(answer)
