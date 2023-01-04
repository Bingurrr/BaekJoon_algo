import sys
from collections import deque

t = int(sys.stdin.readline().rstrip())

def R(arr) :
    new_arr = []
    for i in reversed(arr) :
        new_arr.append(i)
    return new_arr

for i in range(t) :
    flag = 0
    c = 0
    p = sys.stdin.readline().rstrip()
    n = int(sys.stdin.readline().rstrip())
    arr = sys.stdin.readline().rstrip()[1:-1].split(',')
    if n == 0 :
        arr = []
    arr = deque(arr)
    for j in range(len(p)) :
        if p[j] == 'R' :
            c += 1
        else :
            if len(arr) < 1 :
                print("error")
                flag = 1
                break
            else :
                if c % 2 == 0 :
                    arr.popleft()
                else :
                    arr.pop()
    if flag == 0 :
        if c %2 == 0 :
            print("[" + ",".join(arr) + "]")
        else :
            arr.reverse()
            print("[" + ",".join(arr) + "]")
