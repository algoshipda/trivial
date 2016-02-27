#include <bits/stdc++.h>
using namespace std;
typedef long long lld;
const double PI = 3.14159265359;

const int MN = 1e5 + 10;
struct Cake
{
	int id;
	lld v;
	Cake(){}
	Cake(int _id, lld _v): id(_id),v(_v){}

	bool operator < (const Cake& rhs) const
	{
		return v < rhs.v;
	}
};

int n;
Cake C[MN];

double s[MN * 4];

double query(int x, int y, int id = 1, int l = 0, int r = n - 1)
{
	if(y < l || r < x) return 0.0;
	if(x <= l && r <= y) return s[id];
	int mid = (l + r) >> 1;
	return max(query(x, y, id << 1, l, mid), query(x, y, id << 1 | 1, mid + 1, r));
}

void put(int pos, double val, int id = 1, int l = 0, int r = n - 1)
{
	if(l == r){
		s[id] = val;
		return;
	}
	int mid = (l + r) >> 1;
	if(pos <= mid){
		put(pos, val, id << 1, l, mid);
	}else{
		put(pos, val, id << 1 | 1, mid + 1, r);
	}
	s[id] = max(s[id << 1], s[id << 1 | 1]);
}

int main()
{
	cin >> n;
	vector<lld> ca;
	for(int i = 0; i < n; ++i){
		int r, h;
		cin >> r >> h;
		C[i].id = i;
		C[i].v = (lld)r * r * h;
	}
	sort(C, C + n);
	
	queue<pair<double, int>> q;
	for(int i = 0; i < n;){
		do{
			double x = query(0, C[i].id);
			q.push(make_pair(x + PI * C[i].v, C[i].id));
			++i;
		}while(i < n && C[i].v == C[i - 1].v);
		while(!q.empty()){
			put(q.front().second, q.front().first);
			q.pop();
		}
	}
	cout << fixed;
	cout << setprecision(10);
	cout << s[1] << '\n';
}
