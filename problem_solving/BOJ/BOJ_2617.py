n,m=map(int,raw_input().split())
adj=[[0]*(n+1) for i in xrange(n+1)]
for i in xrange(m):
	x,y=map(int,raw_input().split())
	adj[x][y]=1
ans=vcnt=0
vis=[0]*(n+1)
def dfs(cur, v):
	vis[cur]=vcnt
	ret=1
	for i in xrange(1,n+1):
		if(v and adj[cur][i] or not v and adj[i][cur]):
			if(vis[i]!=vcnt):
				ret+=dfs(i,v)
	return ret
for i in xrange(1,n+1):
	vcnt+=1
	x=dfs(i,0)
	y=dfs(i,1)
	if(max(x,y)-1>n/2):
		ans+=1
print ans		
