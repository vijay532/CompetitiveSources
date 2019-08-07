#https://www.codechef.com/AUG19B/problems/KS1
import random 

f=open('output.txt','w');

def test():
	t=random.randint(1,10)
	f.write(str(t) + "\n")

	for i in range(t):
		n=random.randint(2,10)
		f.write(str(n) + "\n")
		for j in range(n):
			m=random.randint(1,10)
			f.write(str(m) + " ")
		f.write("\n")

test()
f.close()
