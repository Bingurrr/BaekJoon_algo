def solution(arr):
    if len(arr) == 1 :
        return [-1]
    else :
        a = sorted(arr)
        arr.remove(a[0])
    return arr
  
  
  
#   def solution(arr):
#     if len(arr) == 1 :
#         return [-1]
#     else :
#         arr.remove(min(arr))
#     return arr
