import copy
class Point:
	def __init__(self, _x = int(1e9), _y = int(1e9)):
		self.x = _x
		self.y = _y

	def __lt__(self, that):
		if self.x != that.x:
			return self.x < that.x
		return self.y < that.y


def ccw(a, b, c):
	k = (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x)
	if k > 0 : return 1
	if k : return -1
	return 0

n = input()
points = []
mpos = Point(int(1e9), int(1e9))
for i in xrange(n):
	x, y = map(int, raw_input().split())
	points.append(Point(x, y))
	if mpos > points[i] :
		mpos = points[i]

tmp = Point(mpos.x, mpos.y)
mpos.x = points[0].x
mpos.y = points[0].y
points[0].x = tmp.x
points[0].y = tmp.y


def cmp(a, b):
	k = ccw(pivot, a, b)
	if k < 0 : return 1
	if k > 0 : return -1
	return a < b

points[1:] = sorted(points[1:], cmp)

stk = []
for p in points:
	while len(stk) >= 2 and ccw(stk[-2], stk[-1], p) <= 0 :
		stk.pop(-1)
	stk.append(p)
print len(stk)
