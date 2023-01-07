def solution(babbling):
    answer = 0
    str = ["aya", "ye", "woo", "ma"]
    for i in babbling :
        s = ""
        j = 0
        while(j < len(i)):
            if i[j] == 'a' :
                s += str[0]
                j += 3
            elif i[j] == 'w' :
                s += str[2]
                j += 3
            elif i[j] == 'y' :
                s += str[1]
                j +=2
            elif i[j] == 'm' :
                s += str[3]
                j +=2
            else :
                break
        if s == i :
            answer += 1
                
    return answer