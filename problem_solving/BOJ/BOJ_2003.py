n, m = map(int, raw_input().split())
a = map(int, raw_input().split())
r = 0
ans = 0
s = 0
for l in xrange(n):
	while r < n and s < m:
		s += a[r]
		r += 1
	if(s == m):
		ans += 1
	s -= a[l]
print ans