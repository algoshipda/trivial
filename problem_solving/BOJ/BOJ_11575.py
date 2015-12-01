for tc in xrange(input()):
	n,m=map(int,raw_input().split())
	a=raw_input()
	ans=''
	for x in a:
		ans+=chr(((ord(x)-ord('A'))*n+m)%26+ord('A'))
	print ans
