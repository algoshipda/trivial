#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long lld;

inline int mod (int a)
{
	return (a % 7 + 7) % 7; 
}

lld cnt[200][7];
char ch[8] = "BESIGOM";

int main()
{
	int n;
	cin >> n;
	for(int i = 0; i < n; ++i){
		char c;
		int k;
		cin >> c >> k;
		cnt[c][mod(k)]++;
	}

	lld ans = 0;
	for(int b = 0; b < 7; ++b){
		for(int e = 0; e < 7; ++e){
			for(int s = 0; s < 7; ++s){
				for(int i = 0; i < 7; ++i){
					for(int g = 0; g < 7; ++g){
						for(int o = 0; o < 7; ++o){
							for(int m = 0; m < 7; ++m){
								lld val = (b + e + s + s + i + e) * (g + o + e + s) * (m + o + o);
								if(val % 7 == 0){
									lld v = 1;
									int ar[7] = {b, e, s, i, g, o, m};
									for(int z = 0; z < 7; ++z){
										v *= cnt[ch[z]][ar[z]];
									}
									ans += v;
								}
							}
						}
					}
				}
			}
		}
	}
	cout << ans << '\n';
}