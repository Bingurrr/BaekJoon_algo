def solution(n,a,b):
    num = 0
    e = n
    l = int(n/2)
    k = 2
    i = 1
    li = []
    check = 0
    while (num != n) :
        li = []
        #print(l)
        #print('k',k)
        for i in range(1,l+1) :
            li.append(i * k)
        l = int(l/2)
        k = k * 2
        if (a <= li[0]) and (b <= li[0]) : check = 1
        for j in range(1, len(li)) :
            if (a <= li[j]) and (b <= li[j]) and (a > li[j-1]) and (b > li[j-1]) :
                check = 1
        if check == 1:
            break
        num = num + 1




    return num+1
