import sys
dp=[0]*10005
dp[0]=1
for i in xrange(10000):
    dp[i+1]+=dp[i]
    dp[i+2]+=dp[i]
for line in sys.stdin:
    n=int(line.strip())
    print dp[n]+dp[n-2]
