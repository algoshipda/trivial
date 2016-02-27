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
typedef pair<double, double> pdd;
typedef pair<long long, long long> pll;

const int INF = 987654321;
const long long LINF = 9876543212345;

struct R{
	double x1,y1,x2,y2;
	R(double _x1, double _y1, double _x2, double _y2):x1(_x1),y1(_y1),x2(_x2),y2(_y2){}
};

int N;
vector<R> r;
vector<double> X;
vector<double> Y;

int matched (double ax1, double ay1, double ax2, double ay2, double bx1, double by1, double bx2, double by2)
{
	if((ax1 >= bx1) && (ax2 <= bx2) &&	(ay1 >= by1) && (ay2 <= by2)) 
		return 1;
	return 0;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
#endif
	scanf("%d",&N);
	int i,j,k;
	double ans = 0.0;
	for(k=0;k<N;++k){
		double aa,bb,cc,dd;
		//scanf("%lf %lf %lf %lf ",&aa,&bb,&cc,&dd);
		cin>>aa>>bb>>cc>>dd;
		double a = aa;
		double b = bb;
		double c = aa+cc;
		double d = bb+dd;
		X.pb(a);
		X.pb(c);
		Y.pb(b);
		Y.pb(d);
		r.pb(R(a,b,c,d));
	}

	sort(all(X));
	sort(all(Y));
	for(i=0;i<sz(X)-1;++i){
		for(j=0;j<sz(Y)-1;++j){
			for(k=0;k<sz(r);++k){
				if(matched(X[i],Y[j],X[i+1],Y[j+1],r[k].x1,r[k].y1,r[k].x2,r[k].y2)){
					ans += (X[i+1]-X[i])*(Y[j+1]-Y[j]);
					break;
				}
			}
		}
	}
	if(ans-floor(ans)<0.001){
		printf("%.0f\n",ans);
	}else{
		printf("%.2f\n",ans);
	}

#ifndef ONLINE_JUDGE
	fclose(stdin);
#endif
}
