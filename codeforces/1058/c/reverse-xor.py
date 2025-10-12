
t = int(input())
for _ in range(t):
    n = int(input())
    yes = False
    for x in range(1, 31):
        if n >= (1 << x): continue
        
        ok =  True
        
        if x % 2 == 1:
            
            mid = x // 2
            if (n & (1 << mid )) != 0 : ok = False
                
        for i in range((x + 1) // 2):
            
            b1 = (n & (1  << i)) != 0
            b2 = (n & (1 << (x -  1 - i))) != 0
            
            if b1 != b2: ok = False
        if ok:
            yes = True
            break
        
    print("YES" if yes else "NO")
