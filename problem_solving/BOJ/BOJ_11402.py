n,k,m=map(int,raw_input().split())
dp=[[0]*(m+1) for i in xrange(m+1)]
for i in xrange(m+1):
	for j in xrange(i+1):
		if(i==j or j==0):
			dp[i][j]=1
		else:
			dp[i][j]=(dp[i-1][j-1]+dp[i-1][j])%m
ans=1
while(n and k):
	x=n%m
	y=k%m
	n/=m
	k/=m
	ans=ans*dp[x][y]%m
print ans