def solution(s):
    answer = 1
    l = len(s)
    a = palindrome(s)
    if a == True :
        return len(s)

    for i in range(0, l) :
        q = l - i
        for j in range(0, l-q+2) : 
            t = s[j:j+q-1]
            if palindrome(t) == True :
                aa = len(t)
                return aa

    return answer

def palindrome(s) :
    l = len(s)
    for i in range(len(s)) :
        if s[i] != s[l -i-1] :
            return False
    return True
