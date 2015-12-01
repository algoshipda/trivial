n=input()
path=[]
def rec(x, y):
	for i in xrange(len(path)-1):
		if(path[i]==x or abs(path[i]-x)==y-i):
			return 0
	if(y==n-1):return 1
	ret=0
	for i in xrange(n):
		path.append(i)
		ret+=rec(i,y+1)
		path.pop()
	return ret
cnt=0
for i in xrange(n):
	path.append(i)
	cnt+=rec(i,0)
	path.pop()
print cnt
