import math
def solution(nums):
    answer = 0

    l = len(nums)
    check = 0
    for i in range(l-2) :
        for j in range(i+1, l-1) :
            for k in range(j+1, l) :
                n1 = nums[i]
                n2 = nums[j]
                n3 = nums[k]
                n = n1+n2+n3
                for a in range(2, n//2) :
                    if n % a == 0 : 
                        check = 1
                if check == 0 :
                    answer = answer + 1
                check = 0



    # [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    #print('Hello Python')

    return answer
