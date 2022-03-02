def solution(nums):
    kind = len(set(nums))
    n = len(nums)/2
    if n > kind :
        return kind
    else :
        return n
