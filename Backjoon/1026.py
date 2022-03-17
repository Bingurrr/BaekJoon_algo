N = int(input())
a = list( map(int, input().split()))
b = list( map(int, input().split()))

a = sorted(a)
b = sorted(b, reverse = True)

answer = 0
for i in range(N) :
  answer = answer + a[i]*b[i]
print(answer)
