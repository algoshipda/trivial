class Edge:
    def __init__(self, _v = 0, _c = 0, _r = None):
        self.v = _v
        self.c = _c
        self.r = _r

    def __str__(self):
        return (('%d %d %d')%(self.v, self.c, 1))

def addEdge(adj, u, v, c):
    ue = Edge()
    ve = Edge()
    ue.v = v
    ve.v = u
    ue.c = c
    ve.c = 0
    ue.r = ve
    ve.r = ue
    adj[u].append(ue)
    adj[v].append(ve)
    

inf = int(1e9)
n, m = map(int, raw_input().split())
s, t = map(int, raw_input().split())
s -= 1
t -= 1
adj =[[] for i in xrange(2 * n)]
for i in xrange(n):
    addEdge(adj, 2 * i, 2 * i + 1, input())

for i in xrange(m):
    u, v = map(int, raw_input().split())
    u -= 1
    v -= 1
    addEdge(adj, 2 * u + 1, 2 * v, inf)
    addEdge(adj, 2 * v + 1, 2 * u, inf)

src = 2 * s
snk = 2 * t + 1

while True:
    parent = [-1] * (2 * n)
    parentEdge = [Edge() for i in xrange(2 * n)]
    q = [src]
    parent[src] = src
    for cur in q:
        for edge in adj[cur]:
            if edge.c > 0 and parent[edge.v] == -1 :
                parent[edge.v] = cur
                parentEdge[edge.v] = edge
                q.append(edge.v)

    if parent[snk] == -1: break
    f = inf

    s = snk
    while s != src:
        f = min(f, parentEdge[s].c)
        s = parent[s]

    s = snk
    while s != src:
        parentEdge[s].c -= f
        parentEdge[s].r.c += f
        s = parent[s]

vis = [0] * (2 * n)
q = [src]
vis[src] = 1
for cur in q:
    for edge in adj[cur]:
        if edge.c > 0 and not vis[edge.v] :
            q.append(edge.v)
            vis[edge.v] = 1

ans = []
for i in xrange(n):
    if vis[2 * i] and not vis[2 * i + 1]:
        ans.append(i + 1)
ans.sort()

print ' '.join(map(str, ans))
