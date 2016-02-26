from heapq import *
import sys
sys.setrecursionlimit(10**6)
class Node:
	def __init__(self, _id, _cost):
		self.id = _id
		self.cost = _cost
	def __eq__(self, rhs):
		return self.id == rhs.id and self.cost == rhs.cost
	def __ne__(self, rhs):
		return not (self.id == rhs.id and self.cost == rhs.cost)
	def __gt__(self, rhs):
		return self.cost > rhs.cost
	def __ge__(self, rhs):
		return self.cost >= rhs.cost
	def __le__(self, rhs):
		return self.cost <= rhs.cost
	def __lt__(self, rhs):
		return self.cost < rhs.cost

class Edge:
	def __init__(self, _nxt, _weight):
		self.nxt = _nxt
		self.weight = _weight

buf=[]
idx=0
def myread():
    global buf
    global idx
    if(len(buf)>idx):
        idx+=1
        return int(buf[idx-1])
    buf+=raw_input().split()
    idx+=1
    return int(buf[idx-1])

n = myread()
m = myread()
adj = [[] for i in xrange(n + 1)]
for i in xrange(m):
	u = myread()
	v = myread()
	w = myread()
	adj[u].append(Edge(v, w))

s = myread()
t = myread()


dist = [int(1e9)] * (n + 1)
dist[s] = 0
pq = []
heappush(pq, Node(s, 0))
while len(pq) > 0:
	cur = heappop(pq)
	if dist[cur.id] != cur.cost: continue
	for edge in adj[cur.id]:
		ndist = dist[cur.id] + edge.weight
		if dist[edge.nxt] > ndist:
			dist[edge.nxt] = ndist
			heappush(pq, Node(edge.nxt, ndist))

print dist[t]