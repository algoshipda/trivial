n=input()
adj=[[0]*(n+1) for i in xrange(n+1)]
grp=[-1]*(n+1)
gcnt=0
for i in xrange(input()):
	x,y=map(int,raw_input().split())
	adj[x][y]=adj[y][x]=1
def dfs(cur):
	grp[cur]=gcnt
	for i in xrange(1,n+1):
		if(grp[i]==-1 and adj[cur][i]):
			dfs(i)
for i in xrange(1,n+1):
	if(grp[i]==-1):
		dfs(i)
		gcnt+=1
print gcnt
def process(g):
	ret=-1
	chk=[int(1e9)]*(n+1)
	for i in xrange(1,n+1):
		if(grp[i]!=g):continue
		dist=[-1]*(n+1)
		q=[i]
		dist[i]=0
		for cur in q:
			for j in xrange(1,n+1):
				if(adj[cur][j] and dist[j]==-1):
					dist[j]=dist[cur]+1
					q.append(j)
		x=max(dist)
		if(ret==-1 or chk[ret]>x):
			ret=i
			chk[i]=x
	return ret
		
ans=[]
for i in xrange(gcnt):
	ans.append(process(i))
print '\n'.join(map(str,sorted(ans)))
