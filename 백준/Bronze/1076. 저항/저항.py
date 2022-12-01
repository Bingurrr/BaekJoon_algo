str1 = input()
str2 = input()
str3 = input()

answer = ""
dic = {'black':1, "brown":10, "red":100, "orange":1000, "yellow":10000, "green":100000, "blue":1000000, "violet":10000000, "grey":100000000, "white":1000000000 }

if str1 == "black" and str2 == "black" :
  print(0)
elif str1 == "black" :
  print(str(len(str(dic[str2]))-1) + str(dic[str3])[1:])
else :
  print(str(len(str(dic[str1]))-1) +str(len(str(dic[str2]))-1) + str(dic[str3])[1:])
