import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.*;

public class Main {
	public static void main(String args[]) {
		Solver s = new Solver();
		s.solve();
	}
}

class Solver {
	Solver() {}
	
	String[] board;
	ArrayList<Integer>[] adj;
	int aCount, bCount;
	int[][] aNum, bNum;
	int[] vis, match;
	int vcnt;
	public void solve() {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		InputReader in = new InputReader(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
	
		int t = in.nextInt();
		while(t-- > 0){
			int n = in.nextInt();
			int m = in.nextInt();
			board = new String[n];
			aCount = 0;
			bCount = 0;
			aNum = new int[n][m];
			bNum = new int[n][m];
			for(int i = 0; i < n; ++i){
				board[i] = in.next();
				for(int j = 0; j < m; ++j){
					if(board[i].charAt(j) == 'x') continue;
					if(j % 2 == 0){
						aNum[i][j] = aCount;
						++aCount;
					}else{
						bNum[i][j] = bCount;
						++bCount;
					}
				}
			}
			
			adj = (ArrayList<Integer>[]) new ArrayList[aCount];
			for(int i = 0; i < aCount; ++i) adj[i] = new ArrayList<>();
			for(int i = 0; i < n; ++i){
				for(int j = 0; j < m; j+=2){
					if(board[i].charAt(j) == 'x') continue;
					for(int dx = -1; dx <= 1; ++dx){
						for(int dy = -1; dy <= 1; dy+=2){
							int nx = i + dx;
							int ny = j + dy;
							if(0 <= nx && nx < n && 0 <= ny && ny < m && board[nx].charAt(ny) == '.'){
								adj[aNum[i][j]].add(bNum[nx][ny]);
							}
						}
					}
				}
			}
			
			vis = new int[aCount];
			match = new int[bCount];
			Arrays.fill(vis, 0);
			Arrays.fill(match, -1);
			
			int matched = 0;
			for(int i = 0; i < aCount; ++i){
				++vcnt;
				matched += dfs(i);
			}
			out.println(aCount + bCount - matched);			
		}
		out.close();
	}

	int dfs(int cur)
	{
		if(vis[cur] == vcnt) return 0;
		vis[cur] = vcnt;
		for(int nxt : adj[cur]){
			if(match[nxt] == -1 || dfs(match[nxt]) > 0){
				match[nxt] = cur;
				return 1;
			}
		}
		return 0;
	}
	static class InputReader {
		public BufferedReader reader;
		public StringTokenizer tokenizer;

		public InputReader(InputStream stream) {
			reader = new BufferedReader(new InputStreamReader(stream), 32768);
			tokenizer = null;
		}

		public String next() {
			while (tokenizer == null || !tokenizer.hasMoreTokens()) {
				try {
					tokenizer = new StringTokenizer(reader.readLine());
				} catch (IOException e) {
					throw new RuntimeException(e);
				}
			}
			return tokenizer.nextToken();
		}

		public int nextInt() {
			return Integer.parseInt(next());
		}
	}
}