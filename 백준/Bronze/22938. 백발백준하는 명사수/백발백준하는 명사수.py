from math import sqrt
import sys

x = sys.stdin.readline
arr = list(map(int, x().split()))
arr2 = list(map(int, x().split()))

dist = sqrt((arr[0] - arr2[0]) ** 2.0 + (arr[1] - arr2[1]) ** 2.0)
total = arr[2] + arr2[2]

if dist >= total: 
    print("NO")
else: 
    print("YES")