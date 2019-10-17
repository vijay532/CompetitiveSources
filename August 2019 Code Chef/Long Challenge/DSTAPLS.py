t = int(input())

while t:
    n, k = list(map(int, input().split()))

    # In each box
    temp = n//k

    if temp % k == 0:
        print('YES')
    else:
        print('NO')

    t -= 1

