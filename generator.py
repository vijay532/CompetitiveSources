#https://www.codechef.com/SEPT19B/problems/GDSUB
import random 

f=open('output.txt','w');

def test():
    n=random.randint(1,10)
    f.write(str(n) + " ")
    k=random.randint(1,n)
    f.write(str(k) + "\n")
    for i in range(n):
        n=random.randint(2,8000)
        f.write(str(n) + " ")
test()
f.close()
