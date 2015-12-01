gcd=lambda a,b: a if not b else gcd(b,a%b)
for tc in xrange(input()):
	a=map(int,raw_input().split())
	n=len(a)
	ans = 1
	for i in xrange(n):
		for j in xrange(i+1,n):
			ans=max(ans,gcd(a[i],a[j]))
	print ans
