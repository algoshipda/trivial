#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair
using namespace std;

typedef pair<int,int> pii;
const int INF = 1234567890;
struct Tree{
	vector<int> tree;
	int first;
	Tree(int _size){
		for(first=1;first<_size;first<<=1);
		tree = vector<int>(_size<<2,INF);
	}

	void update(int pos, int val)
	{
		pos += first;
		tree[pos] = val;
		pos>>=1;
		while(pos>0){
			tree[pos] = min(tree[pos<<1],tree[pos<<1|1]);
			pos>>=1;
		}
	}

	int query(int l, int r)
	{
		int ret = INF;
		l+=first;
		r+=first;
		while(l<=r){
			ret = min(tree[l],min(tree[r],ret));
			l = (l+1)>>1;
			r = (r-1)>>1;
		}
		return ret;
	}
};

struct Ship{
	int x1,y1,x2,y2,w;
	Ship(int _x1, int _y1, int _x2, int _y2,int _w): x1(_x1),y1(_y1),x2(_x2),y2(_y2),w(_w){}
};
int T,N,K,L;


int main()
{
	freopen("input.txt","r",stdin);
	int i,j,k;
	scanf("%d",&T);
	while(T--){
		vector<int> xpos;
		vector<int> ypos;
		vector<Ship> ship;
		vector<pii> cannon;
		vector<int> ans;
		
		scanf("%d%d%d",&N,&K,&L);
		for(i=0;i<K;++i){
			int x1,y1,x2,y2,w;
			scanf("%d%d%d%d%d",&x1,&y1,&x2,&y2,&w);
			xpos.pb(x1);
			xpos.pb(x2);
			ypos.pb(y1);
			ypos.pb(y2);
			if(x1>x2)swap(x1,x2);
			if(y1>y2)swap(y1,y2);
			ship.pb(Ship(x1,y1,x2,y2,w));
		}

		for(i=0;i<L;++i){
			int pos, dir;
			scanf("%d%d",&pos,&dir);
			if(dir)xpos.pb(pos);
			else ypos.pb(pos);
			cannon.pb(mp(pos,dir));
		}

		sort(xpos.begin(),xpos.end());
		sort(ypos.begin(),ypos.end());
		xpos.erase(unique(xpos.begin(),xpos.end()),xpos.end());
		ypos.erase(unique(ypos.begin(),ypos.end()),ypos.end());
		
		Tree xtr((int)xpos.size());
		Tree ytr((int)ypos.size());		
		for(i=0;i<L;++i){
			pii cur = cannon[i];
			if(cur.second){
				int xidx = lower_bound(xpos.begin(),xpos.end(),cur.first)-xpos.begin();
				xtr.update(xidx,i);
			}else{
				int yidx = lower_bound(ypos.begin(),ypos.end(),cur.first)-ypos.begin();
				ytr.update(yidx,i);
			}
		}
		ans = vector<int>(L,0);
		for(i=0;i<K;++i){
			int x1 = lower_bound(xpos.begin(),xpos.end(),ship[i].x1)-xpos.begin();
			int y1 = lower_bound(ypos.begin(),ypos.end(),ship[i].y1)-ypos.begin();
			int x2 = lower_bound(xpos.begin(),xpos.end(),ship[i].x2)-xpos.begin();
			int y2 = lower_bound(ypos.begin(),ypos.end(),ship[i].y2)-ypos.begin();
			int w = ship[i].w;
			int xcannon = xtr.query(x1,x2);
			int ycannon = ytr.query(y1,y2);
			int can = min(xcannon,ycannon);
			if(can==INF)continue;
			ans[can] = max(ans[can], w);
		}
		for(i=0;i<L;++i)printf("%d\n",ans[i]);
	}
	fclose(stdin);
}