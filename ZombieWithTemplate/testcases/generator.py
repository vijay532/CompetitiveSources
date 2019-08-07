import random

f = open('finalt8.txt','w')

def test():
    t = random.randint(1,5)
    
    f.write(str(t) + "\n")

    for i in range(t):
        h = random.randint(1,10000)
        k = random.randint(1,10000)
        z = random.randint(1,10000)
        m = random.randint(1,10000)
        r = random.randint(500,100000)
        
        f.write(str(h)+" "+str(k)+" "+str(z)+" "+str(m)+" "+str(r)+"\n")

        for i in range(r):
            
            if i in range(10):
                a = random.randint(1,10000)
                
                while a == h:
                    a = random.randint(1,10000)
                
                f.write(str(a)+" "+str(h)+"\n")
            elif i in range(20):
                a = random.randint(1,10000)
                
                while a == k:
                    a = random.randint(1,10000)
                
                f.write(str(a)+" "+str(k)+"\n")
                
            elif i in range(30):
                a = random.randint(1,10000)
                
                while a == z:
                    a = random.randint(1,10000)
                
                f.write(str(a)+" "+str(z)+"\n")
                
            elif i in range(40):
                a = random.randint(1,10000)
                
                while a == m:
                    a = random.randint(1,10000)
                
                f.write(str(a)+" "+str(m)+"\n")
                
            else:
                a = random.randint(1,10000)
                b = random.randint(1,10000)
                
                while a==b:
                    a = random.randint(1,10000)
                
                f.write(str(a)+" "+str(b)+"\n")
            
test()
f.close()