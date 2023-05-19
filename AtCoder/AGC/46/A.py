a = int(input())
k = 0
t = 1
count = 1
while t == 1 :
     k = k + a
     count = count + 1
     if k % 360 == 0 :
         break

print(count)