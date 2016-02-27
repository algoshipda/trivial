inf = int(1e9)
for tc in xrange(input()):
    n, m = map(int, raw_input().split())
    board = [map(int, raw_input().split()) for i in xrange(n)]
    summ = sum(map(sum, board))
    
    source = n * m
    sink = n * m + 1
    adj = [[] for i in xrange(n * m + 2)]
    
    class Edge:
        def __init__(self):
            self.v = 0
            self.c = 0
            self.r = None

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

    for i in xrange(n):
        for j in xrange(m):
            if (i + j) % 2 :
                addEdge(adj, source, i * m + j, board[i][j])
                for dir in zip([0, 1, 0, -1], [1, 0, -1, 0]):
                    nx = i + dir[0]
                    ny = j + dir[1]
                    if 0 <= nx < n and 0 <= ny < m:
                        addEdge(adj, i * m + j, nx * m + ny, inf)
            else:
                addEdge(adj, i * m + j, sink, board[i][j])
    
    while True:
        level = [-1] * (n * m + 2)
        it = [0] * (n * m + 2)
        q = [source]
        level[source] = 0
        for cur in q:
            for edge in adj[cur]:
                if edge.c > 0 and level[edge.v] == -1:
                    level[edge.v] = level[cur] + 1
                    q.append(edge.v)
        
        if level[sink] == -1: break
        
        def dfs(s, t, f):
            if s == t : return f
            for nxt in xrange(it[s], len(adj[s])):
                it[s] += 1
                edge = adj[s][nxt]
                if edge.c > 0 and level[edge.v] == level[s] + 1:
                    x = dfs(edge.v, t, min(f, edge.c))
                    if x:
                        edge.c -= x
                        edge.r.c += x
                        return x
            return 0

        while True:
            x = dfs(source, sink, inf)
            if not x:
                break
            summ -= x
    print summ


