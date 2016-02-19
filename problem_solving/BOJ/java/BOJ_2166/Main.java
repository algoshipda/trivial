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

	int[] match;
	ArrayList<Integer>[] adj;
	int[] vis;
	int vcnt;
	int n, m;
	int[][] board;
	int[][][] num;
	int[] count;
	public void solve() {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		InputReader in = new InputReader(inputStream);
		PrintWriter out = new PrintWriter(outputStream);

		int n = in.nextInt();
		Point[] points = new Point[n];

		for(int i = 0; i < n; ++i){
			Point p = new Point();
			p.x = in.nextInt();
			p.y = in.nextInt();
			points[i] = p;
		}

		long ans = 0;
		for(int i = 0; i < n; ++i){
			ans += signedArea(points[0], points[i], points[(i + 1) % n]);
		}
		ans = Math.abs(ans);
		out.println(String.format("%d.%d", ans / 2, ans % 2 * 5));
		out.close();
	}

	long signedArea(Point a, Point b, Point c)
	{
		return (long)(b.x - a.x) * (c.y - a.y) - (long)(b.y - a.y) * (c.x - a.x);
	}
	static class Point
	{
		int x, y;
		Point(){x=0;y=0;}
		Point(int _x, int _y){x=_x;y=_y;};
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
