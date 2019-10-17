from itertools import accumulate
t = int(input())

while t:
    n, q = [int(x) for x in input().split()]
    s = input()

    if (n < 3):
        for _ in range(q):
            l, r = [int(x) for x in input().split()]
            print('NO')
    else:
        temp = [0] * (n-2)
        for i in range(n-2):
            if (s[i] == s[i+1]) or (s[i+2] == s[i+1]) or (s[i] == s[i+2]):
                temp[i] = 1
        temp = list(accumulate(temp))
        
        for _ in range(q):
            l, r = [int(x) for x in input().split()]

            if (r - l) < 2:
                print('NO')
                continue
            r -= 3
            if l == 1:
                if temp[r] > 0:
                    print('YES') 
                else:
                    print('NO')
            else:
                if (temp[r] - temp[l-2]) > 0:
                    print('YES')
                else:
                    print('NO')
    
    t -= 1