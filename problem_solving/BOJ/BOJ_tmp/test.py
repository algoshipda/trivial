import sys
for line in sys.stdin:
	n = int(line.strip())
	dp = [0]*(250+1)
	dp[0] = 1
	dp[1] = 1
	dp[2] = 3
	for i in xrange(3,n+1):
		dp[i] = dp[i-1] + (dp[i-2]<<1)
	print dp[n]