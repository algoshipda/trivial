def ccw(a, b, c):
	k = (b[0] - a[0]) * (c[1] - a[1]) - (b[1] - a[1]) * (c[0] - a[0])
	if k > 0: return 1
	if k: return -1
	return 0
n = input()
h = map(int, raw_input().split())

ans = 0
for i in xrange(n):
	cnt = 0
	for j in xrange(i):
		valid = True
		for k in xrange(j + 1, i):
			if ccw([i, h[i]], [k, h[k]], [j, h[j]]) >= 0:
				valid = False
				break
		if valid: cnt += 1
	for j in xrange(i + 1, n):
		valid = True
		for k in xrange(i + 1, j):
			if ccw([i, h[i]], [k, h[k]], [j, h[j]]) <= 0:
				valid = False
				break
		if valid: cnt += 1
	ans = max(ans, cnt)
print ans
