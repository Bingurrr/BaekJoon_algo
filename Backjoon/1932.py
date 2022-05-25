n = int(input())
arr = []
for i in range(n) :
    a = list(map(int, input().split()))
    arr.append(a)


def solution(triangle):
    answer = 0
    max = 0
    arr = triangle
    h = len(arr)
    for i in range(1, h) :
        for j in range(0, i+1) :
            if j == 0 :
                arr[i][j] += arr[i-1][j]
            elif i == j :
                arr[i][j] += arr[i-1][j-1]
            else :
                if arr[i-1][j] > arr[i-1][j-1] :
                    max = arr[i-1][j]
                    arr[i][j] += max
                else :
                    max = arr[i-1][j-1]
                    arr[i][j] += max
    
    arr[h-1] = sorted(arr[h-1])
    answer = arr[h-1][h-1]
    return answer

print(solution(arr))
