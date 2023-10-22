p = int(input())

def swap(a,b,arr) :
    tmp = arr[a]
    arr[a] = arr[b]
    arr[b] = tmp
    return arr


def sol(arr) :
    cnt = 0
    for j in range(len(arr)) :
        for i in range(j-1, -1, -1) :
            if arr[i] > arr[i+1] :
                arr = swap(i, i+1, arr)
                cnt += 1
    return cnt


while p > 0 :
    p -= 1
    ans = 0
    
    arr = list(map(int, input().split()))
    testcase = arr[0]
    students = arr[1:]
    
    ans = sol(students)

    print(testcase, ans)