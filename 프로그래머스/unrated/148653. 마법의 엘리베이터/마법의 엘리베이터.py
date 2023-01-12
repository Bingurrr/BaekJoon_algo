def solution(storey):
    answer = 0

    while storey > 0 :
        k = storey % 10
        if k > 5 :
            answer += 10 - k
            storey += k
        elif k == 5 and (storey//10) % 10 >= 5 :
            answer += 10 - k
            storey += k
        else :
            answer += k
        storey //= 10
        
    return answer