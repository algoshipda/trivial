for tc in xrange(input()):
    n, m = map(int, raw_input().split())
    board = [raw_input() for i in xrange(n)]
    num = [[0 for j in xrange(m)] for i in xrange(n)]
    acnt = 0
    bcnt = 0
    for i in xrange(n):
        for j in xrange(m):
            if board[i][j] == 'x': continue
            if j % 2:
                num[i][j] = acnt
                acnt += 1
            else:
                num[i][j] = bcnt
                bcnt += 1
    adj = [[] for i in xrange(acnt)]
    for i in xrange(n):
        for j in xrange(m):
            if board[i][j] == 'x': continue
            if j % 2:
                for dx in [-1, 0, 1]:
                    for dy in [-1, 1]:
                        nx = i + dx
                        ny = j + dy
                        if 0 <= nx < n and 0 <= ny < m and board[nx][ny] == '.':
                            adj[num[i][j]].append(num[nx][ny])

    vis = [0] * acnt
    match = [-1] * bcnt
    vcnt = 0
    def dfs(cur):
        if vis[cur] == vcnt: return 0
        vis[cur] = vcnt
        for nxt in adj[cur]:
            if match[nxt] == -1 or dfs(match[nxt]):
                match[nxt] = cur
                return 1
        return 0
    
    matched = 0
    for i in xrange(acnt):
        vcnt += 1
        matched += dfs(i)
    print acnt + bcnt - matched
