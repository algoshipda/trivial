#include <bits/stdc++.h>
using namespace std;

int main()
{
	int s=0,n;
	scanf("%d",&n);
	for(int i=0;i<n;++i){
		char c[10];
		int x;
		scanf("%s",c);
		if(c[0]=='a'){
			if(c[1]=='l'){
				s=0xFFFFF;
				continue;
			}
		}
		if(c[0]=='e'){
			s=0;
			continue;
		}
		scanf("%d",&x);
		--x;
		switch(c[0]){
		case 'a':
			s|=(1<<x);
			break;
		case 'r':
			s&=~(1<<x);
			break;
		case 'c':
			printf("%d\n",(s&(1<<x))?1:0);
			break;
		case 't':
			s^=(1<<x);
		}
	}
}
