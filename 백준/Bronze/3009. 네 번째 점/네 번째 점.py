n1 = []
n2 = []
for _ in range(3):
    x, y = map(int, input().split())
    n1.append(x)
    n2.append(y)
for i in range(3):
    if n1.count(n1[i]) == 1:
        x4 = n1[i]
    if n2.count(n2[i]) == 1:
        y4 = n2[i]
print(x4, y4)