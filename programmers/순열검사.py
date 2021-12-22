def solution(arr):
    answer = True
    t = sorted(arr)
    big_num = sorted(arr, reverse = True)[0]
    arr = sorted(arr, reverse = True)

    for i in range(big_num) : 

        if i+1 != t[i] : return False
        
    return answer
