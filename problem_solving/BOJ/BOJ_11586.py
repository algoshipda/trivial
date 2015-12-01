n=input()
a=[raw_input() for i in xrange(n)]
x=input()
if(x==3):
	print '\n'.join(a[::-1])
	exit()
elif(x==2):
	for i in xrange(n):
		a[i]=a[i][::-1]
print '\n'.join(a)
