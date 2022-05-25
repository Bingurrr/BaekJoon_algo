bullets = input()
p = 0
a = 0
arr = bullets + bullets[0]
for j in range(len(arr)-1) :
    if arr[j] == '0' and arr[j+1] == '0' :
        p += 1
    elif arr[j] == '0' and arr[j+1] == '1' :
        a += 1
if p == a or a == 0:
    print("EQUAL")
elif p < a :
    print("ROTATE")
else :
    print("SHOOT")
