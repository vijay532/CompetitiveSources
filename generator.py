#https://www.codechef.com/SEPT19B/problems/GDSUB
import random 

f=open('output.txt','w');

def test():
    t=random.randint(1,10)
    f.write(str(t) + "\n")
    for i in range(t):
        n=random.randint(1,10)
        f.write(str(n) + " ")
        k=random.randint(1,10)
        f.write(str(n) + "\n")
        for i in range(n):
            m=random.randint(1,20)
            f.write(str(m) + " ")
        f.write("\n")
test()
f.close()
