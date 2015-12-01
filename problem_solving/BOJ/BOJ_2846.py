n=input()
a=map(int,raw_input().split())
dp=[0]*n
for i in xrange(1,n):
		if(a[i-1]<a[i]):
			dp[i]=dp[i-1]+a[i]-a[i-1]
print max(dp)
