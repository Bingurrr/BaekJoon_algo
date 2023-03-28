a, b = input().split()

ans = 0
sum_a = 0
sum_b = 0

for i in range(len(a)) :
    sum_a += int(a[i])
for j in range(len(b)) :
    sum_b += int(b[j])

ans = sum_a * sum_b
print(ans)
