def signedArea(a, b, c):
	return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);

class Point:
	def __init__(self, _x, _y):
		self.x = x
		self.y = y
		
n = input()
points = []
for i in xrange(n):
	x, y = map(int, raw_input().split())
	points.append(Point(x, y))

ans = 0
for i in xrange(n):
	ans += signedArea(points[0], points[i], points[(i + 1) % n])
ans = abs(ans)

print('%d.%d' % (ans / 2, ans % 2 * 5))