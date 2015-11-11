for tc in xrange(input()):
	n,m=map(int,raw_input().split())
	a,b,x=[map(int,raw_input().split()) for i in xrange(3)]
	x+=x[0:m]
	ans=0
	for i in xrange(n):
		if(a<=x[i:i+m]<=b):ans+=1
	print ans