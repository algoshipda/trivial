        /* 2-SAT라고 한다. x번 막대기를 제거 한다를 x라는 명제로 정의하고 명제 의존 관계를 그래프로 만든다.
           SCC, 위상정렬을 이용해 해를 찾는다. 자세히 잘 모르겠다. 일단 따라 해보자.*/

        #include <cstdio>
        #include <algorithm>
        #include <vector>
        #include <stack>
        #define pb(A) push_back((A))
        #define mp(A,B) make_pair((A),(B))
        using namespace std;   

        typedef pair<int, int> pii;
        struct Line{
                int x1,y1,x2,y2;
                Line(){};
                Line(int _x1, int _y1, int _x2, int _y2):x1(_x1),y1(_y1),x2(_x2),y2(_y2){};
        };
        int n;
        vector< vector<int> > adj;

        int ccw(int x1, int y1, int x2, int y2)
        {
                int ret = x1*y2- y1*x2;
                if(ret>0) return 1;
                if(ret<0) return -1;
                return 0;
        }
        int ccw(int x1, int y1, int x2, int y2, int x3, int y3)
        {
                return ccw(x2-x1,y2-y1,x3-x1,y3-y1);
        }
        bool isCross(const Line& a, const Line& b)
        {
                int A = ccw(a.x1,a.y1,a.x2,a.y2,b.x1,b.y1) * ccw(a.x1,a.y1,a.x2,a.y2,b.x2,b.y2);
                int B = ccw(b.x1,b.y1,b.x2,b.y2,a.x1,a.y1) * ccw(b.x1,b.y1,b.x2,b.y2,a.x2,a.y2);
                return A<=0 && B<=0;
        }
        void makeGraph(const vector<Line>& stick)
        {
                adj.resize(n*2);
                //각 사람은 한 막대기를 집으면 다른 막대기 두개는 집을 수 없다.
                //i번째 막대기를 잡는다는 명제를 2*i, 잡지않는다를 2*i+1이라 하자.
                for(int i=0;i<n;i+=3){
                        int j = i+1;
                        int k = i+2;
                        adj[2*i].pb(2*j+1);
                        adj[2*i].pb(2*k+1);
                        adj[2*j].pb(2*i+1);
                        adj[2*j].pb(2*k+1);
                        adj[2*k].pb(2*i+1);
                        adj[2*k].pb(2*j+1);
                }
                
                //i와 j막대기가 교차한다고 하면 i를 집지 않으면 j를 집어야 하고 j를 집지 않으면 i를 집어야 한다.
                for(int i=0;i<n;++i){
                        for(int j=i+1;j<n;++j){
                                if(isCross(stick[i],stick[j])){
                                        adj[2*i+1].pb(2*j);
                                        adj[2*j+1].pb(2*i);
                                }
                        }
                }
        }


        vector<int> sccId;
        vector<int> discovered;
        stack<int> st;
        int sccCounter, vertexCounter;

        int scc(int here)
        {
                int ret = discovered[here] = vertexCounter++;
                st.push(here);
                int sz = adj[here].size();
                for(int i=0;i<sz;++i){
                        int there = adj[here][i];
                        if(discovered[there] == -1)
                                ret = min(ret, scc(there));
                        else if(sccId[there] == -1)
                                ret = min(ret, discovered[there]);
                }
                
                if(ret == discovered[here]){
                        while(true){
                                int t = st.top();
                                st.pop();
                                sccId[t] = sccCounter;
                                if(t==here) break;
                        }
                        ++sccCounter;
                }
                return ret;
        }

        vector<int> tarjanSCC(){
                sccId = discovered = vector<int>(adj.size(), -1);
                int sz = adj.size();
                for(int i=0;i<sz;++i){
                        if(discovered[i] == -1)
                                scc(i);
                }
                return sccId;
        }
        vector<int> solve2SAT()
        {
                vector<int> label = tarjanSCC();
                for(int i=0;i<2*n;i+=2){
                        if(label[i] == label[i+1])
                                return vector<int>();
                }
                
                vector<int> value(2*n,-1);
                vector<pii> order;
                for(int i=0;i<2*n;++i)
                        order.pb(mp(-label[i],i));
                
                sort(order.begin(), order.end());
                
                for(int i=0; i<2*n; ++i) {
                        int vertex = order[i].second;
                        int variable = vertex/2;
                        int isTrue = vertex%2==0;
                        if(value[variable] != -1) continue;
                        value[variable] = !isTrue;
                }
                return value;
        }
        int main()
        {
                vector<Line> s;
                scanf("%d",&n);
                for(int i=0;i<n;++i){
                        for(int j=0;j<3;++j){
                                int x1,y1,x2,y2;
                                scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
                                s.pb(Line(x1,y1,x2,y2));
                        }
                }
                n*=3;
                makeGraph(s);
                vector<int> answer = solve2SAT();
                int sz = answer.size();
                if(sz){
                        int cnt = 0;
                        for(int i=0;i<n;++i)cnt+=answer[i];
                        printf("%d\n",cnt);
                        for(int i=0;i<n;++i){
                                if(answer[i])printf("%d ",i+1);
                        }
                }else
                        printf("-1\n");

        }
