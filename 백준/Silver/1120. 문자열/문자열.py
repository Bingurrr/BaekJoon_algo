A, B = input().split()

result = []
for i in range(len(B) - len(A) + 1):
    cnt = 0
    for j in range(len(A)):
        if A[j] != B[i + j]:
            cnt += 1
    result.append(cnt)

print(min(result))