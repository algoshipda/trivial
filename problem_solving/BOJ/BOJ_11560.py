for tc in xrange(input()):
	m,n=map(int,raw_input().split())
	dp=[[0 for i in xrange(405)] for j in xrange(m+1)]
	dp[0][0]=1;
	for i in xrange(1,m+1):
		for j in xrange(n+1):
			for k in xrange(i+1):
				dp[i][j+k]+=dp[i-1][j]
	print dp[m][n]
