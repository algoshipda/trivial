#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int INF = 987654321;
int t;
char A[5005];
char B[5005];
int dp[505][505];
int cnt[27];
int A_first_color[30];
int B_first_color[30];
int A_last_color[30];
int B_last_color[30];
int main()
{
        for(scanf("%d",&t);t;--t){
                memset(A_first_color,0,sizeof(A_first_color));
                memset(B_first_color,0,sizeof(B_first_color));
                memset(dp,0,sizeof(dp));
                memset(cnt,0,sizeof(cnt));
                scanf("%s%s",A+1,B+1);
                int asz = strlen(A+1);
                int bsz = strlen(B+1);
                for(int i=1;i<=asz;++i){
                        if(!A_first_color[A[i]-'A'])A_first_color[A[i]-'A'] = i;
                        A_last_color[A[i]-'A'] = i;
                        cnt[A[i]-'A']++;
                }
                for(int i=1;i<=bsz;++i){
                        if(!B_first_color[B[i]-'A'])B_first_color[B[i]-'A'] = i;
                        B_last_color[B[i]-'A'] = i;
                        cnt[B[i]-'A']++;
                }

                for(int i=0;i<26;++i){
                        dp[A_first_color[i]][0] = B_first_color[i] || A_first_color[i] != A_last_color[i] ? -A_first_color[i] : 0;
                        dp[0][B_first_color[i]] = A_first_color[i] || B_first_color[i] != B_last_color[i] ? -B_first_color[i] : 0;
                        if(A_last_color[i]==0 && B_first_color[i] != B_last_color[i]){
                                dp[0][B_last_color[i]] = B_last_color[i];
                        }
                        if(B_last_color[i]==0 && A_first_color[i] != A_last_color[i]){
                                dp[A_last_color[i]][0] = A_last_color[i];
                        }
                }
                printf("%d ",dp[1][0]);
                for(int i=2;i<=asz;++i){
                        dp[i][0] += dp[i-1][0];
                        printf("%d ",dp[i][0]);
                }
                printf("\n");
                printf("%d ",dp[0][1]);
                for(int i=2;i<=bsz;++i){
                        dp[0][i] += dp[0][i-1];
                        printf("%d ",dp[0][i]);
                }
                printf("\n");
                for(int I=1;I<=asz;++I){
                        for(int J=1;J<=bsz;++J){
                                int i = I;
                                int j = J;
                                int im = (I-1);
                                int jm = (J-1);
                                int k = I+J;
                                int ca = A[I]-'A';
                                int cb = B[J]-'A';
                                
                                dp[i][j] = INF;
                                
                                if(cnt[ca]<2){
                                        dp[i][j] = min(dp[i][j], dp[im][j]);
                                }else if(A_last_color[ca] == I && J >= B_last_color[ca]){
                                        printf("<last>A ");
                                        dp[i][j] = min(dp[i][j], dp[im][j] + k);
                                }else if(A_first_color[ca] == I && J < B_first_color[ca]){
                                        printf("<first>A ");
                                        dp[i][j] = min(dp[i][j], dp[im][j] - k);
                                }else{
                                        dp[i][j] = min(dp[i][j], dp[im][j]);
                                }
                                
                                if(cnt[cb]<2){
                                        dp[i][j] = min(dp[i][j], dp[i][jm]);
                                }else if(B_last_color[cb] == J && I >= A_last_color[cb]){
                                        printf("<last>B ");
                                        dp[i][j] = min(dp[i][j], dp[i][jm] + k);
                                }else if(B_first_color[cb] == J && I < A_first_color[cb]){
                                        printf("<first>B ");
                                        dp[i][j] = min(dp[i][j], dp[i][jm] - k);
                                }else{
                                        dp[i][j] = min(dp[i][j], dp[i][jm]);
                                }
                                printf("%d %d %d\n", I, J, dp[i][j]);
                        }
                }
                printf("%d\n",dp[asz][bsz]);
        }
}
