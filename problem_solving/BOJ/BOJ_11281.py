import sys
sys.setrecursionlimit(10**6)
n,m=map(int,raw_input().split())
adj=[[] for i in xrange(n*2+10)]
radj=[[] for i in xrange(n*2+10)]
neg=lambda x: x+n if x<=n else x-n
visited=[0]*(n*2+10)
scc=[0]*(n*2+10)
for i in xrange(m):
	x,y=map(int,raw_input().split())
	if(x<0):x=-x+n
	if(y<0):y=-y+n
	adj[neg(x)].append(y)
	adj[neg(y)].append(x)
	radj[y].append(neg(x))
	radj[x].append(neg(y))
stk=[]
vcnt=1
def dfs(cur):
	visited[cur]=vcnt
	for nxt in adj[cur]:
		if not visited[nxt]:
			dfs(nxt)
	stk.append(cur)
def dfs2(cur):
	scc[cur]=vcnt;
	for nxt in radj[cur]:
		if not scc[nxt]:
			dfs2(nxt)
for cur in xrange(1,n<<1|1):
	if not visited[cur]:
		dfs(cur)
for cur in reversed(stk):
	if not scc[cur]:
		dfs2(cur)
		vcnt+=1
valid=True
for i in xrange(1,n+1):
	if(scc[i]==scc[i+n]):
		valid=False
		break
print 1 if valid else 0
if not valid:
	exit()
for i in xrange(1,n+1):
	print 0 if scc[i]<scc[i+n] else 1,