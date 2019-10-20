# This will give you 100 points
# using prefix xor array
# link https://www.youtube.com/watch?v=0aYvuNdWzn0&feature=youtu.be
from collections import defaultdict

t = int(input())

while t:
    n = int(input())
    A = list(map(int, input().split()))

    pre_xor = 0
    c = defaultdict(list)
    c[0].append(1)

    for i in range(n):
        c[pre_xor ^ A[i]].append(i+2)
        pre_xor = pre_xor ^ A[i]
    
    # print(c)
    final_ans = 0
    for key, value in c.items():
        sum_key = 0
        current_len = len(value)
        for i in range(1, current_len):
            sum_key += i * (current_len - i) * (value[i] - value[i-1] - 1)
            sum_key += ((i) * (i-1))//2
        # print(sum_key)
        final_ans += sum_key

    
    print(final_ans)
    t -= 1