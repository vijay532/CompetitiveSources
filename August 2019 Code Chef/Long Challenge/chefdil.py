from collections import Counter
t = int(input())

while t:
    s = input()

    c = Counter(s)

    if c['1'] % 2 != 0:
        print('WIN')
    else:
        print('LOSE')
    t -= 1