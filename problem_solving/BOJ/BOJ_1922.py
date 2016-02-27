
n = input()
m = input()

p = range(n + 1)
rank = [0] * (n + 1)
def findSet(cur):
	if(cur == p[cur]): return cur
	p[cur] = findSet(p[cur])
	return p[cur]

def mergeSet(u, v):
	if(rank[u] < rank[v]): u, v = v, u
	p[v] = u
	if(rank[u] == rank[v]):
		rank[u]+=1

edges = []
for i in xrange(m):
	u, v, w = map(int, raw_input().split())
	edges.append([w, u, v])
edges.sort()

ans = 0
for edge in edges:
	u = findSet(edge[1])
	v = findSet(edge[2])
	if(u == v): continue
	ans += edge[0]
	mergeSet(u, v)
print ans