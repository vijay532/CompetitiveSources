t = int(input())

while t:
    n = int(input())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))

    max_ = 0
    for i in range(n):
        temp = a[i] * 20 - b[i] * 10
        temp = temp if temp > 0 else 0
        if max_ < temp:
            max_ = temp

    print(max_)
    t -= 1