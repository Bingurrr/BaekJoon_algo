def solution(k, tangerine):
    answer = 0
    dict = {}
    for i in tangerine :
        if i in dict :
            dict[i] += 1
        else :
            dict[i] = 1
            
    num = []
    
    for i in dict :
        num.append(dict[i])
        
    num.sort(key = lambda x :x, reverse = True)
    
    for i in num :
        answer += 1
        k -= i
        if k <= 0 : break

    return answer