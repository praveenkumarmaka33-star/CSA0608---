#include <stdio.h>
#include <string.h>
#define N 100
int main(){int n,W,l[N],dp[N+1],next[N+1];char w[N][64];
printf("Word count and line width: ");if(scanf("%d%d",&n,&W)!=2||n<1||n>=N||W<1)return 1;
for(int i=0;i<n;i++){scanf("%63s",w[i]);l[i]=strlen(w[i]);if(l[i]>W){puts("Word wider than line");return 1;}}
dp[n]=0;next[n]=n;
for(int i=n-1;i>=0;i--){int used=0;dp[i]=1000000000;for(int j=i;j<n;j++){used+=l[j]+(j>i);if(used>W)break;int unused=W-used,pen=(j==n-1)?0:unused*unused;if(pen+dp[j+1]<dp[i])dp[i]=pen+dp[j+1],next[i]=j+1;}}
puts("DP suffix costs:");for(int i=0;i<=n;i++)printf("dp[%d]=%d next=%d\n",i,dp[i],next[i]);
puts("Layout:");for(int i=0,line=1;i<n;line++){int j=next[i],used=0;printf("Line %d: ",line);for(int k=i;k<j;k++){printf("%s%s",w[k],k+1<j?" ":"");used+=l[k]+(k>i);}int u=W-used;printf(" | unused=%d penalty=%d\n",u,j==n?0:u*u);i=j;}
printf("Minimum penalty=%d\n",dp[0]);}
