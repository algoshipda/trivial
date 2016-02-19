#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int cnt[200][2];
int n;
string t = "BESIGOM";
int main()
{
	cin >> n;
	for(int i = 0; i < n; ++i){
		char c;
		int v;
		cin >> c >> v;
		cnt[c][(v % 2 + 2) % 2]++;
	}

	long long ans = 0;
	for(int b = 0; b < 2; ++b){
		for(int e = 0; e < 2; ++e){
			for(int s = 0 ; s < 2; ++s){
				for(int i = 0; i < 2; ++i){
					for(int g = 0; g < 2; ++g){
						for(int o = 0; o < 2; ++o){
							for(int m = 0; m < 2; ++m){
								int v = (b + e + s + s + i + e) * (g + o + e + s) * (m + o + o);
								if(v % 2 == 0){
									long long c = 1;
									int x[7] = {b, e, s, i, g, o, m};
									for(int k = 0; k < 7; ++k){
										c *= cnt[t[k]][x[k]];
									}
									ans += c;
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