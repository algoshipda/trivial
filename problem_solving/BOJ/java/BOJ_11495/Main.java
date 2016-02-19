import java.util.*;
public class Main {
	public static void main(String args[])
	{
		Solver s = new Solver();
		s.solve();
	}
}

class Solver
{
	Solver(){}

	int[][] board;
	int source, sink;
	ArrayList<Edge>[] adj;
	int[] iter;
	int[] level;
	public void solve()
	{
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		while(t-- > 0){
			int n = sc.nextInt();
			int m = sc.nextInt();
			board = new int[n][m];
			
			int sum = 0;
			for(int i = 0; i < n; ++i){
				for(int j = 0; j < m; ++j){
					board[i][j] = sc.nextInt();
					sum += board[i][j];
				}
			}
			source = n * m;
			sink = n * m + 1;
			adj = (ArrayList<Edge>[])new ArrayList[n * m + 2];
			for(int i = 0; i < n * m + 2; ++i) adj[i] = new ArrayList<Edge>();
			for(int i = 0; i < n; ++i){
				for(int j = 0; j < m; ++j){
					if((i + j) % 2 == 0){
						addEdge(source, i * m + j, board[i][j]);
						for(int dx = -1; dx <= 1; ++dx){
							for(int dy = -1; dy <= 1; ++dy){
								if(Math.abs(dx) + Math.abs(dy) == 1){
									int nx = i + dx;
									int ny = j + dy;
									if(0 <= nx && nx < n && 0 <= ny  && ny < m){
										addEdge(i * m + j, nx * m + ny, (int)1e9);
									}
								}
							}
						}
					}else{
						addEdge(i * m + j, sink, board[i][j]);
					}
				}
			}
			
			int ans = 0;
			while(true){
				level = new int[n * m + 2];
				iter = new int[n * m + 2];
				Arrays.fill(level, -1);
				Arrays.fill(iter,  0);
				bfs();
				if(level[sink] == -1) break;
				
				int x = 0;
				while((x = dfs(source, sink, (int)1e9)) > 0) ans += x;
				
			}
			System.out.println(sum - ans);
		}
		sc.close();
	}
	
	void bfs()
	{
		Queue<Integer> q = new LinkedList<Integer>();
		q.add(source);
		level[source] = 0;
		while(!q.isEmpty()){
			int cur = q.poll();
			for(Edge edge : adj[cur]){
				if(edge.cap > 0 && level[edge.nxt] == -1){
					level[edge.nxt] = level[cur] + 1;
					q.add(edge.nxt);
				}
			}
		}
	}
	
	int dfs(int cur, int t, int f)
	{
		if(cur == t) return f;
		for(int i = iter[cur]; i < adj[cur].size() ; ++i){
			iter[cur] += 1;
			Edge edge = adj[cur].get(i);
			if(edge.cap > 0 && level[edge.nxt] == level[cur] + 1){
				int x = dfs(edge.nxt, t, Math.min(f,  edge.cap));
				if(x > 0){
					edge.cap -= x;
					edge.rev.cap += x;
					return x;
				}
			}
		}
		return 0;
	}
	
	void addEdge(int u, int v, int c)
	{
		Edge s = new Edge();
		Edge t = new Edge();
		s.nxt = v;
		t.nxt = u;
		s.cap = c;
		t.cap = 0;
		s.rev = t;
		t.rev = s;
		adj[u].add(s);
		adj[v].add(t);
	}
	
	static class Edge
	{
		int nxt, cap;
		Edge rev;
		Edge(){}
	}
}