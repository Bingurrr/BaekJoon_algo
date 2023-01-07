def solution(babbling):
    answer = 0
    str = ["aya", "ye", "woo", "ma"]
    for i in babbling :
        s = ""
        j = 0
        cnt = -1
        while(j < len(i)):
            if i[j] == 'a' and cnt != 0:
                s += str[0]
                j += 3
                cnt = 0
            elif i[j] == 'w' and cnt != 1 :
                s += str[2]
                j += 3
                cnt = 1
            elif i[j] == 'y' and cnt!= 2 :
                s += str[1]
                j +=2
                cnt = 2
            elif i[j] == 'm' and cnt!= 3 :
                s += str[3]
                j +=2
                cnt = 3
            else :
                break
        if s == i :
            answer += 1
                
    return answer