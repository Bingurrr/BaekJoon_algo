import sys

n = int(input())

arr = list(map(int, input().split()))

x = int(input())

arr_sorted = sorted(arr)

# print(arr_sorted)

start_point = 0
end_point = len(arr) -1
ans = 0

while start_point < end_point :
    if arr_sorted[start_point] + arr_sorted[end_point] == x :
        ans += 1
        start_point += 1
        end_point -= 1
    elif arr_sorted[start_point] + arr_sorted[end_point] > x :
        end_point -= 1
    else :
        start_point += 1

print(ans)