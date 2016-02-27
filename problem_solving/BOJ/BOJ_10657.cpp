#include <iostream>
#include <stack>
using namespace std;

int main()
{
    int n;
    cin >> n;
    stack<int> stk;
    for(int i = 0; i < n; ++i){
        int x, y;
        cin >> x >> y;
        while(!stk.empty() && stk.top() > y) stk.pop();
        stk.push(y);
    }
    cout << stk.size() << '\n';
}
