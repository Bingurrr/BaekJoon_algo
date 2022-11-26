for _ in range(int(input())):
    x = 0
    n, m = input().split()
    for i in range(int(n), int(m)+1):
        x += str(i).count('0')
    print(x)