#include <bits/stdc++.h>
using namespace std;

struct lrh{
    int m, h, o;
    lrh(int _m = 0, int _h = 0, int _o = 0) : m(_m), h(_h), o(_o){}
    bool operator < (const lrh& rhs) const
    {
        if(m != rhs.m) return m < rhs.m;
        return h < rhs.h;
    }
};

int n;
int ans[100005];
int sum[400005];
void update(int pos, int val, int id = 1, int l = 0, int r = n)
{
    if(l == r){
        sum[id] += val;
        return;
    }
    int mid = (l + r)>>1;
    if(pos <= mid){
        update(pos, val, id<<1, l, mid);
    }else{
        update(pos, val, id<<1|1, mid+1, r);
    }
    sum[id] = sum[id<<1] + sum[id<<1|1];
}

int query(int x, int y, int id = 1, int l = 0, int r = n)
{
    if(y < l || r < x) return 0;
    if(x <= l && r <= y) return sum[id];
    int mid = (l + r)>>1;
    return query(x, y, id<<1, l, mid) + query(x, y, id<<1|1, mid+1, r);
}


vector<pair<int,int>> pos[100005];
int main()
{
    scanf("%d", &n);
    vector<lrh> v(n * 2);
    for(int i = 0; i < n; ++i){
        int x, y;
        scanf("%d%d", &x, &y);
        v[i] = lrh(x, i + 1, 1);
        v[i + n] = lrh(y, i + 1, 0);
    }
    sort(v.begin(), v.end());
    for(int i = 0; i < v.size(); ++i){
        pos[v[i].m].push_back(make_pair(v[i].h, v[i].o));
    }
    for(int i = 1; i <= 100000; ++i){
		for(int j = 0; j < pos[i].size(); ++j){
			if(!pos[i][j].second)update(pos[i][j].first, -1);
			ans[pos[i][j].first] += query(j ? pos[i][j-1].first + 1 : 0, pos[i][j].first); 
			if(pos[i][j].second)update(pos[i][j].first, 1);
		}
    }
    for(int i = 1; i <= n; ++i)printf("%d\n",ans[i]);
}
