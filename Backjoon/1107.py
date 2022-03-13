target = int(input())
n = int(input())
if n != 0 :
  wrong = input().split()
else :
  wrong = []

min_click = abs(target - 100)
for i in range(1000000) :
  pos = True
  for num in str(i) :
    if num in wrong :
      pos = False
  if (pos) :
    if min_click > abs(i - target) + len(str(i)) :
      min_click = abs(i-target) + len(str(i))
      if i > target :
        break
print(min_click)
