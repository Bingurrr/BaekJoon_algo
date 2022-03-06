def solution(n):
    answer = ''
    if n == 1 :
        return '1'
    cnt = 0
    while n >= 1  :
        num = n % 3
        n = n//3 - (num == 0)
        
        if num == 1 :
            answer = '1' + answer
        elif num == 2 :
            answer = '2' + answer
        else :
            answer = '4' + answer
    return answer
