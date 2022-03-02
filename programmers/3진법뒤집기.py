def solution(n):
    answer = 0
    l = []
    while(n > 1) :
        l.append(int(n%3))
        n = n/3
    mul = len(l)-1
    for i in l :
        answer = answer + pow(3,mul)*i
        mul = mul -1
    if answer==0 : answer = 1
    return answer

