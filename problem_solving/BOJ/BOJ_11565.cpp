#include <stdio.h>
char s[1005];
int a,b;
int main()
{
	scanf("%s",s);
	for(int i=0;s[i];++i)a+=s[i]=='1';
	scanf("%s",s);
	for(int i=0;s[i];++i)b+=s[i]=='1';
	if(a%2 && (a+1>=b) || (a%2)==0 && a>=b){
		puts("VICTORY");
	}else{
		puts("DEFEAT");
	}
}
