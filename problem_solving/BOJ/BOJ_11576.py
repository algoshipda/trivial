n,m=map(int,raw_input().split())
l=input()
a=map(int,raw_input().split())
ans=[]
x=1
c=0
for i in reversed(xrange(l)):
	c+=x*a[i]
	x*=n
x=1
while(c):
	ans.append(c%m)
	c/=m
print ' '.join(map(str,reversed(ans)))

