def fact(k) :
    ret = 1;
    for i in range(1,k+1) :
        ret *= i
    return ret

def solution(n, k):
    answer = []
    num = [1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20]    
    for i in range(1,n+1) :
        factorial_num = fact(n-i)
        for j in range(1,n+1) :
            if factorial_num * j >= k :
                answer.append(num[j-1])
                del num[j-1]
                k -= factorial_num * (j-1)
                break
    return answer