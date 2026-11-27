#include <stdio.h>
#include <stdlib.h>
typedef struct{char id[16];int wt,val;double r;}Item;
int cmp(const void*a,const void*b){double d=((Item*)b)->r-((Item*)a)->r;return(d>0)-(d<0);}
int main(){Item a[80],g[80];int n,C;printf("Count capacity: ");if(scanf("%d%d",&n,&C)!=2||n<1||n>80||C<0||C>1000)return 1;
for(int i=0;i<n;i++){scanf("%15s%d%d",a[i].id,&a[i].wt,&a[i].val);if(a[i].wt<=0||a[i].val<0)return 1;a[i].r=(double)a[i].val/a[i].wt;g[i]=a[i];}
qsort(g,n,sizeof(Item),cmp);int rem=C,ops=0;double gv=0;puts("Fractional greedy:");for(int i=0;i<n&&rem;i++){ops++;int take=g[i].wt<rem?g[i].wt:rem;if(take){double f=(double)take/g[i].wt;printf("%s fraction %.2f\n",g[i].id,f);gv+=f*g[i].val;rem-=take;}}
printf("Fractional value %.2f decisions %d\\n",gv,ops);
    /* Same ratio ordering, but indivisible 0/1 selection: this heuristic can fail. */
    int greedy01=0, cap01=C; puts("0/1 ratio-greedy heuristic:");
    for(int i=0;i<n;i++) if(g[i].wt<=cap01){printf("commit %s (w=%d,v=%d)\\n",g[i].id,g[i].wt,g[i].val);cap01-=g[i].wt;greedy01+=g[i].val;}
    printf("0/1 ratio-greedy value=%d (remaining capacity=%d)\\n",greedy01,cap01);
int dp[81][1001]={0},take[81][1001]={0},states=0;for(int i=1;i<=n;i++)for(int c=0;c<=C;c++){states++;dp[i][c]=dp[i-1][c];if(a[i-1].wt<=c&&a[i-1].val+dp[i-1][c-a[i-1].wt]>dp[i][c])dp[i][c]=a[i-1].val+dp[i-1][c-a[i-1].wt],take[i][c]=1;}
int chosen[80],k=0,c=C;for(int i=n;i;i--)if(take[i][c])chosen[k++]=i-1,c-=a[i-1].wt;puts("0/1 DP selected:");for(int i=k-1;i>=0;i--)printf("%s ",a[chosen[i]].id);printf("\nOptimal value %d; states %d\n",dp[n][C],states);}
