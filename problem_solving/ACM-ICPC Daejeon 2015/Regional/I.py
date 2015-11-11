for tc in xrange(input()):
	n=input()
	a=map(int,raw_input().split())
	m=ans=0
	for x in reversed(a):
		if(x>m):m=x
		else:ans+=m-x
	print ans