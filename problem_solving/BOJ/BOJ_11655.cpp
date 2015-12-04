#include <bits/stdc++.h>
using namespace std;
char s[105];
int main()
{
	gets(s);
	for(int i=0;s[i];++i){
		if('A'<=s[i] && s[i]<='Z'){
			printf("%c",(s[i]-'A'+13)%26+'A');
		}else if('a'<=s[i] && s[i]<='z'){
			printf("%c",(s[i]-'a'+13)%26+'a');
		}else{
			printf("%c",s[i]);
		}
	}
}
