from collections import Counter, defaultdict
t = int(input())

while t:
    n = int(input())
    c = list(map(int, input().split()))
    h = list(map(int, input().split()))

    c2 = defaultdict(int)
    diff = [0] * n

    for i in range(n):
        c2[h[i]] += 1
        lb = (i-c[i]) if (i+1-c[i]) > 0 else 0
        hb = n if (i+1+c[i]) > n else (i+1+c[i])
        diff[lb] += 1
        if hb <= n-1:
            diff[hb] -= 1
        

    
    for i in range(1, n):
        diff[i] += diff[i-1]

    
    c1 = Counter(diff)
    

    l1 = len(c1)
    l2 = len(c2)

    flag = True
    if l1 != l2:
        print('NO')
    else:
        for key, value in c2.items():
            if c1[key] == 0:
                flag = False
                break
            elif c1[key] != c2[key]:
                flag = False
                break
            else:
                pass

        if flag == True:
            print('YES')
        else:
            print('NO')
    t -= 1