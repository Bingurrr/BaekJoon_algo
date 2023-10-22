p = int(input())

def swap(a,b,arr) :
    tmp = arr[a]
    arr[a] = arr[b]
    arr[b] = tmp
    return arr


def sol(arr) :
    cnt = 0
    for i in range(len(arr)-2, -1, -1) :
        if arr[i] > arr[i+1] :
            arr = swap(i, i+1, arr)
            cnt += 1
    return cnt, arr


while p > 0 :
    p -= 1
    ans = 0
    
    arr = list(map(int, input().split()))
    testcase = arr[0]
    students = arr[1:]
    line = []
    
    for i in range(len(students)) :
        line.append(students[i])
        cnt, line = sol(line)
        ans += cnt

    print(testcase, ans)