s = set()

for _ in range(28) : 
    x = int(input())
    s.add(x)

for i in range(30) :
    if i+1 not in s :
        print(i+1)