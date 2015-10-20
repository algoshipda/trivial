# Test : BOJ 2150
# 7 9
# 1 4
# 4 5
# 5 1
# 1 6
# 6 7
# 2 7
# 7 3
# 3 7
# 7 2

class SCC:
	def __init__(self,vcnt):
		self.vertexCount = vcnt
		self.adjacencyList = [[] for i in xrange(self.vertexCount)]

	def addEdge(self, u, v):
		self.adjacencyList[u].append(v)

	def findSCC(self):
		self.scc = [0] * self.vertexCount
		self.visited = [0] * self.vertexCount
		self.stack = []
		sccCount = 0
		for curNode in xrange(self.vertexCount):
			self.DFS1(curNode)
		self.visited = [0] * self.vertexCount
		self.transpose()
		for curNode in reversed(self.stack):
			if not self.visited[curNode]:
				self.DFS2(curNode,sccCount)
				sccCount += 1
		del self.visited
		del self.stack

	def transpose(self):
		rev = [[] for i in xrange(self.vertexCount)]
		for i in xrange(self.vertexCount):
			for x in self.adjacencyList[i]:
				rev[x].append(i)
		self.adjacencyList = rev

	def DFS1(self, curNode):
		if self.visited[curNode]: return False
		self.visited[curNode] = True
		for nextNode in self.adjacencyList[curNode]:
			self.DFS1(nextNode)
		self.stack.append(curNode)

	def DFS2(self, curNode, sccCount):
		if self.visited[curNode]: return False
		self.visited[curNode] = True
		self.scc[curNode] = sccCount
		for nextNode in self.adjacencyList[curNode]:
			self.DFS2(nextNode, sccCount) 
