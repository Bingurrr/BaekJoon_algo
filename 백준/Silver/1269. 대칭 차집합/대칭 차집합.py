_, _ = map(int,input().split())

A = list(map(int,input().split()))
B = list(map(int,input().split()))

x = list(set(A)-set(B))
y = list(set(B)-set(A))
print(len(x) +  len(y))