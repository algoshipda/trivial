n,m=map(int,raw_input().split())
adj=[[0]*(n+1) for i in xrange(n+1)]
for i in xrange(m):
	x=map(int,raw_input().split())
	for i in xrange(1,x[0]):
		adj[x[i]][x[i+1]]=1
order=[]
vis=[0]*(n+1)
def dfs(cur):
	vis[cur]=1
	for i in xrange(1,n+1):
		if adj[cur][i] and not vis[i]:dfs(i)
	order.append(cur)
for i in xrange(1,n+1):
	if not vis[i]:dfs(i)
order=order[::-1]
valid=True
for i in xrange(n):
	for j in xrange(i):
		if(adj[order[i]][order[j]]):
			valid=False
			break
if valid:
	print '\n'.join(map(str,order))
else:
	print 0
