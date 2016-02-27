#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <cassert>
using namespace std;
int n,m,k;
int sx,sy,ex,ey;
struct bus{
	int d,x1,y1,x2,y2;
	bus(){}
	bus(int _d,int _x1, int _y1, int _x2, int _y2):d(_d), x1(_x1),y1(_y1),x2(_x2),y2(_y2){}
};
vector<bus> v;
vector<bool> isEnd;
bool adj(int i, int j){
    bool iv = v[i].x1==v[i].x2?1:0;
    bool jv = v[j].x1==v[j].x2?1:0;
    bool ans = 1;
    if(i==j) return 0;
    if(iv==1 && jv==1){
        if(v[i].x1 != v[j].x1) return 0;
        if( (v[i].y1<=v[j].y1 && v[j].y2<=v[i].y2) ||
            (v[j].y1<=v[i].y1 && v[i].y2<=v[j].y2) ||
            (v[j].y1<=v[i].y2 && v[i].y1<=v[j].y1 && v[i].y2<=v[j].y2) ||
            (v[i].y1<=v[j].y2 && v[j].y1<=v[i].y1 && v[j].y2<=v[i].y2)){
            return 1;
        }
    }else if(iv==0 && jv==0){
        if(v[i].y1 != v[j].y1) return 0;
        if( (v[i].x1<=v[j].x1 && v[j].x2<=v[i].x2) ||
            (v[j].x1<=v[i].x1 && v[i].x2<=v[j].x2) ||
            (v[j].x1<=v[i].x2 && v[i].x1<=v[j].x1 && v[i].x2<=v[j].x2) ||
            (v[i].x1<=v[j].x2 && v[j].x1<=v[i].x1 && v[j].x2<=v[i].x2)){
            return 1;
        }
    }else if(iv==1 && jv==0){
        if((v[i].y1<=v[j].y1 && v[j].y1<=v[i].y2) && (v[j].x1<=v[i].x1 && v[i].x1<=v[j].x2)){
            return 1;
        }
    }else{
        if((v[i].x1<=v[j].x1 && v[j].x1<=v[i].x2) && (v[j].y1<=v[i].y1 && v[i].y1<=v[j].y2)){
            return 1;
        }
    }
    return 0;
}
int bfs(){
	queue<int> q;
	vector<int> dist(k+1,0);
	vector<bool> visit(k+1,0);
	int vsz = v.size();
	for(int i=0;i<k;++i){
        if(v[i].x1==v[i].x2){
            if(v[i].x1 == sx && v[i].y1<=sy && sy<=v[i].y2){
                q.push(i);
                visit[i]=1;
            }
            if(v[i].x1 == ex && v[i].y1<=ey && ey<=v[i].y2)
                isEnd[i]=1;
        }else{
            if(v[i].y1 == sy && v[i].x1<=sx && sx<=v[i].x2){
                q.push(i);
                visit[i]=1;
            }
            if(v[i].y1 == ey && v[i].x1<=ex && ex<=v[i].x2)
                isEnd[i]=1;
        }
	}
	while(!q.empty() && !isEnd[q.front()]){
		int i = q.front();q.pop();
		int d = dist[i];
		for(int j=0;j<k;++j){
            if(adj(i,j) && !visit[j]){
                q.push(j);
                visit[j]=1;
                dist[j]=d+1;
            }
		}
	}
	return dist[q.front()]+1;
}
int main(){
	scanf("%d%d%d",&n,&m,&k);
	isEnd = vector<bool>(k+1,0);
	for(int i=0;i<k;++i){
		int a,b,c,d,e;
		scanf("%d%d%d%d%d",&a,&b,&c,&d,&e);
        if(b==d){
            if(c>e)swap(c,e);
        }else{
            if(b>d)swap(b,d);
		}
		v.push_back(bus(a,b,c,d,e));
	}
	scanf("%d%d%d%d",&sx,&sy,&ex,&ey);

	printf("%d\n",bfs());
	return 0;
}
