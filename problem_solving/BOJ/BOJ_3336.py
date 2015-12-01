import sys
r=lambda : sys.stdin.readline().strip()
n=int(r())
a=[int(r()) for i in xrange(n)]
stk=[]
ans=0
for x in a:
	while True:
		if len(stk)==1 and stk[-1]<=x or len(stk)>=2 and stk[-1]<=x and stk[-2]>=x:
			ans+=x
			stk.pop(-1)
		elif len(stk)>=2 and stk[-1]<=x and stk[-2]<=x:
			ans+=stk[-2]
			stk.pop(-1)
		else:
			stk.append(x)
			break
while len(stk)>=2:
	ans+=stk[-2]
	stk.pop(-1)
print ans
