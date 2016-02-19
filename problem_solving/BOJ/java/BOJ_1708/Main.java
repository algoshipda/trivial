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
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		InputReader in = new InputReader(inputStream);
		PrintWriter out = new PrintWriter(outputStream);	
		s.solve(in, out);
		out.close();
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
	
	
	
	static class Solver {
		Solver() {}
		
		public void solve(InputReader in, PrintWriter out) {
			int n = in.nextInt();
			Point[] points = new Point[n];
			Point min = new Point((int)1e9, (int)1e9);
			for(int i = 0; i < n; ++i){
				points[i] = new Point();
				points[i].x = in.nextInt();
				points[i].y = in.nextInt();
				if(min.compareTo(points[i]) > 0){
					min = points[i];
				}
			}
			
			Point tmp = new Point(min.x, min.y);
			min.x = points[0].x;
			min.y = points[0].y;
			points[0].x = tmp.x;
			points[0].y = tmp.y;
			
			final Point pivot = points[0];
			Arrays.sort(points, 1, points.length, new Comparator<Point>(){
				public int compare(Point p1, Point p2)
				{
					int k = ccw(pivot, p1, p2);
					if(k > 0) return -1;
					if(k < 0) return 1;
					return p1.compareTo(p2);
				}
			});
			Stack<Point> stk = new Stack<>();
			for(Point p : points){
				while(stk.size() >= 2 && ccw(stk.get(stk.size() - 2), stk.get(stk.size() - 1), p) <= 0){
					stk.pop();
				}
				stk.push(p);
			}
			out.println(stk.size());
		}
		
		int ccw(Point a, Point b, Point c)
		{
			
			long v = (long)(b.x - a.x) * (c.y - a.y) - (long)(b.y - a.y) * (c.x - a.x);
			if(v > 0) return 1;
			if(v < 0) return -1;
			return 0;
		}
		
		static class Point
		{
			int x, y;
			Point(){}
			Point(int _x, int _y){
				x = _x;
				y = _y;
			}
			
			int compareTo(Point rhs)
			{
				if(this.x != rhs.x) return this.x - rhs.x;
				return this.y - rhs.y;
			}
		}
	}
}

