n,k=map(int,raw_input().split())
a=map(int,raw_input().split())
q=[]
f=e=0
ans=0
valid=True
for i in xrange(n):
	while(f!=e and q[f]<=i-k):
		f+=1
	if a[i]^((e-f)%2):
		if(i+k>n):valid=False
		q.append(i)
		e+=1
		ans+=1
print ans if valid else 'Insomnia'
