a,b = map(int,input().split())

arr = []
for i in range(a) :
  arr.append(list(map(int, input().split())))
def power(adj,n):
    if n==1:
        return adj
    elif n%2:
        return multi(power(adj,n-1),adj)
    else:
        return power(multi(adj,adj),n//2)

def multi(U, V):
    n = len(U)
    Z = [[0]*n for _ in range(n)]
    
    for row in range(n):
        for col in range(n):
            e = 0
            for i in range(n):
                e += U[row][i] * V[i][col]
            Z[row][col] = e % 1000
    return Z

arr = power(arr,b)

for i in range(a) :
  for j in range(a) :
    print(arr[i][j]%1000, end = " ")
  print()
