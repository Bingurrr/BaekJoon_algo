def solution(num):
    if num == 1 :
        return 0
    answer = 0
    max_try = 500
    while max_try > 0 :
        num = collatz(num)
        answer = answer+1
        if num == 1 :
            return answer
        max_try = max_try - 1
    return -1

def collatz(num) :
    if num % 2 == 0 :
        return num/2
    else :
        return num * 3 + 1
