#include <bits/stdc++.h>
#define pb(a) push_back(a)
#define sz(a) ((int)a.size())
#define all(a) a.begin(),a.end()
#define mp(a,b) make_pair((a),(b))
#define ff first
#define ss second

using namespace std;

typedef long long lld;
typedef unsigned long long llu;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int INF = 2e9;
const long long LINF = 9876543212345;

struct Line{
	int x1,y1,x2,y2;
	Line(int _x1, int _y1, int _x2, int _y2):x1(_x1),y1(_y1),x2(_x2),y2(_y2){}
};
int dx[] = {1,0,-1,0};
int dy[] = {0,-1,0,1};
int L,N;
int cx,cy;
lld ct;
int dir; 
vector<Line> v;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
#endif
	scanf("%d%d",&L,&N);
	int i,j,k;
	int Q = L+1;
	v.pb(Line(Q,-Q,Q,Q));
	v.pb(Line(-Q,-Q,Q,-Q));
	v.pb(Line(-Q,-Q,-Q,Q));
	v.pb(Line(-Q,Q,Q,Q));
	++N;
	while(N--){
		int a;
		char c;
		if(N>=1)
			scanf(" %d %c",&a,&c);
		else a = INF+10000;
		int t = INF;
		for(i=0;i<sz(v);++i){
			if(dir==0){
				if(v[i].x1==v[i].x2 && cx<v[i].x1 && v[i].y1<=cy && cy<=v[i].y2)t = min(t, abs(v[i].x1-cx));
				else if(v[i].y1==v[i].y2 && cy==v[i].y1 && cx<v[i].x1)t = min(t, abs(v[i].x1-cx));
			}else if(dir==1){
				if(v[i].y1==v[i].y2 && cy>v[i].y1 && v[i].x1<=cx && cx<=v[i].x2)t = min(t, abs(v[i].y1-cy));
				else if(v[i].x1==v[i].x2 && cx==v[i].x1 && cy>v[i].y2)t = min(t, abs(v[i].y2-cy));
			}else if(dir==2){
				if(v[i].x1==v[i].x2 && cx>v[i].x1 && v[i].y1<=cy && cy<=v[i].y2)t = min(t, abs(v[i].x2-cx));
				else if(v[i].y1==v[i].y2 && cy==v[i].y1 && cx>v[i].x2)t = min(t, abs(v[i].x2-cx));
			}else if(dir==3){
				if(v[i].y1==v[i].y2 && cy<v[i].y1 && v[i].x1<=cx && cx<=v[i].x2)t = min(t, abs(v[i].y2-cy));
				else if(v[i].x1==v[i].x2 && cx==v[i].x1 && cy<v[i].y1)t = min(t, abs(v[i].y1-cy));
			}
		}
		if(t>a){
			int nx = cx + dx[dir] * a;
			int ny = cy + dy[dir] * a;
			if(cx>nx || cx==nx && cy>ny)
				v.pb(Line(nx,ny,cx,cy));
			else v.pb(Line(cx,cy,nx,ny));
			if(c=='L')
				dir = (dir+3)%4;
			else dir = (dir+1)%4;
			cx = nx;
			cy = ny;
			ct += a;
		}else{
			printf("%lld\n",ct+t);
			return 0;
		}
	}
		
#ifndef ONLINE_JUDGE
	fclose(stdin);
#endif
}
