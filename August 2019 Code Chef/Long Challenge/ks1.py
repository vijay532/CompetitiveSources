t = int(input())
# This will give u 50 points
# find all sub-arrays such that in that sub-array(starting at i and ending at j) ai xor ai+1 xor .....xor aj = 0
# above sub-array would contribute j-i to the count value
while t:
    n = int(input())
    A = list(map(int, input().split()))

    count = 0
    for i in range(n-1):
        temp = A[i]
        for j in range(i+1, n):
            temp = temp ^ A[j]
            if temp == 0:
                count = count + (j-i)
    
    print(count)
    t -= 1