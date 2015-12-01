for tc in xrange(input()):
	x=input()
	l=1
	r=x
	while(l<r):
		mid=(l+r+1)>>1
		if(mid*(mid+1)/2<=x):
			l=mid
		else:
			r=mid-1
	print l
