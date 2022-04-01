N = int(input())
animal = []
a2 = []
a3 = []

def combinations(a,b) :
  ret = 1
  if b == 3 :
    ret = a*(a-1)*(a-2)//6
    return ret
  if b == 2 :
    ret = a*(a-1)//2
    return ret

for _ in range(N) :
  a = int(input())
  if a >= 3 :
    a3.append(a)
  if a == 2 :
    a2.append(a)
  animal.append(a)
num_animal = sum(animal)
answer = combinations(num_animal, 3)

for i in range(len(a3)) :
  answer -= combinations(a3[i], 3)
  answer -= combinations(a3[i], 2) * (num_animal - a3[i])

answer -= len(a2) * (num_animal - 2)
print(answer)
