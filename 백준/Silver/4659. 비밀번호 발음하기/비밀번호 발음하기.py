arr = ['a','e','i','o','u']


while True :
    s = input() 
    if s == 'end' : break
    flag = [False, True, True]
    for i in range(len(s)) :
        if flag[0] == False and s[i] in arr :
            flag[0] = True
        
        # 조건 3
        if i > 0 and s[i] is s[i-1] and not (s[i] == 'e' or s[i] == 'o') :
            flag[1] = False
            break

        # 조건 2
        if i > 1 :
            if s[i] in arr and s[i-1] in arr and s[i-2] in arr :
                flag[2] = False
                break
            elif s[i] not in arr and s[i-1] not in arr and s[i-2] not in arr :
                flag[2] = False
                break

    if False in flag :
        print('<' + s + '>' + ' is not acceptable.')
    else :
        print('<' + s + '>' + ' is acceptable.') 