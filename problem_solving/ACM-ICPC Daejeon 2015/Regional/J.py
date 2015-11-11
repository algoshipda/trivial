prime=[1]*1001
prime[0]=prime[1]=0
for i in xrange(2,1001):
	if prime[i]:
		for j in xrange(i*i,1001,i):
			prime[j]=0
for tc in xrange(input()):
	n=input()
	valid=False
	for i in xrange(2,n+1):
		for j in xrange(i,n+1):
			if(i+j>n):break
			if(prime[i] and prime[j] and prime[n-i-j]):
				print ' '.join(map(str,sorted([i,j,n-i-j])))
				valid=True
				break
		if valid:break