n = int(input())

for i in range(n) :
    str = input()
    cnt = 1
    ans = 0
    for j in range(len(str)) :
        if str[j] == 'O' :
            ans += cnt
            cnt += 1
        else :
            cnt = 1
    print(ans)