# Input : aaasack . Output : a3s1a1c1k1 
message = str(input())
cnt = 1
x = 1
j = message[x:x+1]
for i in message:
    
   if i in j:
        
        cnt += 1
   else:
        print(i, end='')
        print(cnt, end='')
        cnt = 1
    x += 1
    j = message[x:x+1]
