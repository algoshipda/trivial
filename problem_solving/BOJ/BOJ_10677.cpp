#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;


int main()
{
	int t;
	cin >> t;
	while(t--){
		string a, b;
		cin >> a >> b;
		int a0 = a[0] - '0';
		int a1 = a[1] - '0';
		int a2 = a[2] - '0';
		int b0 = b[0] - '0';
		int b1 = b[1] - '0';
		int b2 = b[2] - '0';
		for(int i = 10; i <= 15000; ++i){
			int v = 1ll * i * i * a0 + i * a1 + a2;
			int cb2 = b2 - v;
			long long d = b1 * b1 - 1ll * 4 * b0 * cb2;
			if(d < 0) continue;
			int r = sqrt(1.0 * d) + 0.5;
			if(1ll * r * r != d) continue;
			if((-b1 + r) % (2 * b0)) continue;
			int y1 = (-b1 + r) / (2 * b0);
			if(10 <= y1 && y1 <= 15000){
				cout << i << ' ' << y1 <<'\n' ;
				break;
			}
		}
	}
}