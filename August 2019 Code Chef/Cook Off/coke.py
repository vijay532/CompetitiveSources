t = int(input())

while t:
    n, m, k, l, r = [int(x) for x in input().split()]

    cp = []
    for i in range(n):
        cost, price = list(map(int, input().split()))
        cp.append((cost, price))

    cp.sort(key=lambda x: x[1])

    p = float('-inf')
    flag = False
    for temp, price in cp:

        if temp < k:
            temp = min(temp + m, k)
        elif temp > k:
            temp = max(temp - m, k)
        else:
            pass

        if l <= temp and temp <= r:
            p = price
            flag = True
            break

    if flag:
        print(p)
    else:
        print(-1)

    t -= 1