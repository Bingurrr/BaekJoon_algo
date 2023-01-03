s = input()

arr = s.split('-')

ans = 0
idx = 0
for i in arr :
    if idx == 0 :
        p = i.split('+')
        idx = 1
        for j in p :
            ans += int(j)
    else :
        p = i.split('+')
        for j in p :
            ans -= int(j)

print(ans)
