for tc in xrange(input()):
	n=input()
	a=map(int,raw_input().split())
	x=0
	for i in xrange(n):
		for j in xrange(i+1,n):
			if(a[i]>a[j]):x+=1
	print 'NO' if x%2 else 'YES'
