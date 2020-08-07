#https://www.codechef.com/SEPT19B/problems/GDSUB
import random 

f=open('output.txt','w');

def test():
    t=random.randint(1,10)
    f.write(str(t) + "\n")
    for i in range(t):
        n=random.randint(2,10)
        f.write(str(n) + "\n")
        for n in range(n):
            k=random.randint(0,45)
            f.write(str(k) + " ")
            m=random.randint(k+1,46)
            f.write(str(m) + "\n")
test()
f.close()
