t = int(input())

def find(a1,a2,c1,c2):
    flag = 0
    if a1 > a2 and c1 > c2:
        flag = 1
    if a1 < a2 and c1 < c2:
        flag = 1
    if a1 == a2 and c1 == c2:
        flag = 1
    
    return flag

while t:
    a1, a2, a3, c1, c2, c3 = list(map(int, input().split()))

    x = find(a1, a2, c1, c2)
    y = find(a1, a3, c1, c3)
    z = find(a2, a3, c2, c3)


    if x and y and z:
        print('FAIR')
    else:
        print('NOT FAIR')
    
    t -= 1