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

const int INF = 987654321;
const long long LINF = 9876543212345;

double b0,b1,b2,b3;
double t0,t1,t2,t3;
double a0,a1,a2,a3;
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
#endif
	while(scanf("%lf%lf%lf%lf%lf%lf%lf%lf",&bo,&b1,&b2,&b3,&t0,&t1,&t2,&t3)!=EOF){
		a0=t0-b0;
		a1=t1-b1;
		a2=t2-b2;
		a3=t3-b3;
		double l = 0.0;
		double r = 1.0;
		for(int i=0;i<100;++i){
			double mid1 = (r+2*l)/3;
			double mid2 = (2*r+l)/3;
			double ll = a0 + a1*mid1 + a2*mid1*mid1 + a3*mid1*mid1*mid1;
			double rr = a0 + a1*mid2 + a2*mid2*mid2 + a3*mid2*mid2*mid2;
			if() 
		}
	}
	
#ifndef ONLINE_JUDGE
	fclose(stdin);
#endif
}
	