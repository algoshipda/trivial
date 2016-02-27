#include <stdio.h>
int t,i,j,x,size;
int main()
{
	freopen("input.txt","r",stdin);
    scanf("%d",&t);
    for(i=0;i<t;i++) {
        scanf("%d",&size);
        for(j=0;j<size;j++) {
            for(x=0;x<size;x++) {
                if(j==0||x==0||j==size-1||x==size-1){printf("# ");}
                else printf("J ");
            }
            printf("\n");
        }
        printf("\n");
    }
    return 0;
}