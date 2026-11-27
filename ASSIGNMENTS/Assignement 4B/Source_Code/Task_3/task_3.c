#include <stdio.h>
#define N 8
#define M 13
#define I 999999
typedef struct{int u,v,w;}E;
E e[M]={{0,1,4},{0,2,3},{1,2,1},{1,3,5},{2,3,7},{2,4,8},{3,4,2},{3,5,6},{4,5,3},{4,6,4},{5,6,2},{6,7,3},{5,7,8}};
char*nm[N]={"A","B","C","D","E","F","G","H"};
void bf(E*x,int m,char*label){int d[N];for(int i=0;i<N;i++)d[i]=I;d[0]=0;for(int p=1;p<N;p++){int ch=0;for(int i=0;i<m;i++)if(d[x[i].u]<I&&d[x[i].u]+x[i].w<d[x[i].v])d[x[i].v]=d[x[i].u]+x[i].w,ch=1;printf("%s pass %d changed=%d\n",label,p,ch);if(!ch)break;}int cyc=0;for(int i=0;i<m;i++)if(d[x[i].u]<I&&d[x[i].u]+x[i].w<d[x[i].v])cyc=1;printf("Reachable negative cycle: %s\n",cyc?"YES":"NO");if(!cyc)for(int i=0;i<N;i++)printf("%s=%d ",nm[i],d[i]);puts("");}
int main(){int g[N][N],d[N],p[N],done[N]={0};for(int i=0;i<N;i++)for(int j=0;j<N;j++)g[i][j]=i==j?0:I;for(int i=0;i<M;i++)g[e[i].u][e[i].v]=g[e[i].v][e[i].u]=e[i].w;for(int i=0;i<N;i++)d[i]=I,p[i]=-1;d[0]=0;puts("Dijkstra finalisation:");for(int z=0;z<N;z++){int u=-1;for(int i=0;i<N;i++)if(!done[i]&&(u<0||d[i]<d[u]))u=i;if(u<0||d[u]==I)break;done[u]=1;printf("%s:%d ",nm[u],d[u]);for(int v=0;v<N;v++)if(!done[v]&&g[u][v]<I&&d[u]+g[u][v]<d[v])d[v]=d[u]+g[u][v],p[v]=u;}puts("");for(int i=0;i<N;i++)printf("%s dist=%d pred=%s\n",nm[i],d[i],p[i]<0?"-":nm[p[i]]);
E neg[6]={{0,1,10},{0,2,1},{2,3,1},{3,4,1},{1,4,-20},{4,5,2}};puts("Negative edge B->E=-20. Prediction: E may be finalised early via C-D-E before B is processed; Dijkstra is unsafe.");bf(neg,6,"negative edge");
E cyc[7]={{0,1,1},{1,2,2},{2,3,2},{3,1,-5},{3,4,1},{4,5,1},{0,5,20}};puts("Reachable cycle B->C=2,C->D=2,D->B=-5 has total -1:");bf(cyc,7,"cycle");
int f[N][N],r[N][N];for(int i=0;i<N;i++)for(int j=0;j<N;j++)f[i][j]=g[i][j],r[i][j]=(i==j||g[i][j]<I);for(int k=0;k<N;k++)for(int i=0;i<N;i++)for(int j=0;j<N;j++){if(f[i][k]<I&&f[k][j]<I&&f[i][k]+f[k][j]<f[i][j])f[i][j]=f[i][k]+f[k][j];r[i][j]|=r[i][k]&&r[k][j];}puts("Floyd distances:");for(int i=0;i<N;i++){for(int j=0;j<N;j++)if(f[i][j]>=I)printf(" INF");else printf("%4d",f[i][j]);puts("");}puts("Warshall reachability:");for(int i=0;i<N;i++){for(int j=0;j<N;j++)printf("%d ",r[i][j]);puts("");}}
