import sys

input = sys.stdin.readline

n, m = map(int, input().split())

shark_r = int(n/2)
shark_c = int(n/2)

arr = []
ans = [0,0,0]
prior_arr = []

arr_1 = []
arr_2 = []
arr_3 = []
arr_4 = []

for _ in range(n) :
    arr.append(list(map(int, input().split())))

def add_priority() :
    r = shark_r
    c = shark_c
    term = 1
    direction = [(0,-1),(1,0),(0,1),(-1,0)]
    k = 0
    num = 0
    flag = False
    while True:
        for i in range(term) :
            r += direction[k][0]
            c += direction[k][1]
            prior_arr.append(arr[r][c])
            if r == shark_r and c < shark_c :
                arr_3.append(num)
            elif r == shark_r and c > shark_c :
                arr_4.append(num)
            elif r < shark_r and c == shark_c :
                arr_1.append(num)
            elif r > shark_r and c == shark_c :
                arr_2.append(num)
            num += 1
            if r < 0 or c < 0 or r >= n or c >= n :
                flag = True
                break
        k += 1
        if k == 2 or k == 4 :
            term += 1
            if k == 4 : k = 0

        if flag == True :
            break

# 뒤에꺼 부터 제거
def destroy(x,y) :
    if x == 1 :
        for i in range(y) :
            if y-i-1 >= len(arr_1) or arr_1[y-i-1] >= len(prior_arr) : continue
            prior_arr.pop(arr_1[y-i-1])
    elif x == 2 :
        for i in range(y) :
            if y-i-1 >= len(arr_2) or arr_2[y - i - 1] >= len(prior_arr): continue
            prior_arr.pop(arr_2[y-i-1])
    elif x == 3 :
        for i in range(y) :
            if y-i-1 >= len(arr_3) or arr_3[y - i - 1] >= len(prior_arr): continue
            prior_arr.pop(arr_3[y-i-1])
    elif x == 4 :
        for i in range(y) :
            if y-i-1 >= len(arr_4) or arr_4[y - i - 1] >= len(prior_arr): continue
            prior_arr.pop(arr_4[y-i-1])

def bomb() :
    global prior_arr
    bomb_flag = 1
    while bomb_flag != 0 :
        bomb_flag = 0
        start = 0
        cnt = 1
        for i in range(1, len(prior_arr)) :
            if i >= len(prior_arr) : break
            if prior_arr[start] == prior_arr[i] :
                cnt += 1
            else :
                if cnt >= 4 :
                    bomb_flag = 1
                    if prior_arr[start] == 1 :
                        ans[0] += cnt
                    elif prior_arr[start] == 2 :
                        ans[1] += cnt
                    elif prior_arr[start] == 3:
                        ans[2] += cnt
                    for j in range(cnt) :
                        prior_arr[start+j] = -1
                cnt = 1
                start = i
        prior_arr = [i for i in prior_arr if i != -1]


def change() :
    start = 0
    cnt = 1
    new_arr = []
    for i in range(1,len(prior_arr)) :
        if prior_arr[start] == prior_arr[i] :
            cnt += 1
        else :
            new_arr.append(cnt)
            new_arr.append(prior_arr[start])
            cnt = 1
            start = i
        i += 1
    return new_arr[:n*n-1]

def add_zero() :
    if len(prior_arr) < n*n :
        for i in range(n*n-1 - len(prior_arr)) :
            prior_arr.append(0)

def solve() :
    global prior_arr, ans
    add_priority()
    for _ in range(m) :
        d, s = map(int, input().split())
        add_zero()
        destroy(d,s)
        add_zero()
        bomb()
        add_zero()
        prior_arr = change()
        add_zero()
    print(ans[0] + ans[1]*2 + ans[2]*3)

solve()

