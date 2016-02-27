#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
	int n;
	stack<int> stk;
	cin >> n;
	for(int i=0;i<n;++i){
		string s;
		cin >> s;
		if(s == "push"){
			int x;
			cin >> x;
			stk.push(x);
		}else if(s == "pop"){
			if(stk.empty()){
				cout << -1 << endl;
			}else{
				cout << stk.top() << endl;
				stk.pop();
			}
		}else if(s == "top"){
			cout << (stk.empty() ? -1 : stk.top()) << endl;
		}else if(s == "size"){
			cout << stk.size() << endl;
		}else if(s == "empty"){
			cout << stk.empty() << endl;
		}
	}
}
