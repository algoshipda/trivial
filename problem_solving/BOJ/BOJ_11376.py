import sys
sys.setrecursionlimit(10**6)
n,m=map(int,raw_input().split())
am=[-1]*(n<<1)
bm=[-1]*m
adj=[[] for i in xrange(n<<1)]
vcnt=0
vis=[0]*(n<<1)
for i in xrange(n):
	x=map(int,raw_input().split())
	for j in xrange(x[0]):
		adj[i].append(x[j+1]-1)
		adj[i+n].append(x[j+1]-1)
def dfs(cur):
	if(vis[cur]==vcnt):return 0
	vis[cur]=vcnt
	for nxt in adj[cur]:
		if(bm[nxt]==-1 or dfs(bm[nxt])):
			bm[nxt]=cur
			am[cur]=nxt
			return 1
	return 0
ans=0
for i in xrange(n<<1):
	vcnt+=1
	ans+=dfs(i)
print ans