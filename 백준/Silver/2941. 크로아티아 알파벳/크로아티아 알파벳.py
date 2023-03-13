arr = ['c=', 'c-', 'dz=', 'd-', 'lj', 'nj', 's=', 'z=']
str = input()

for i in arr :
    str = str.replace(i, '*') 
print(len(str))