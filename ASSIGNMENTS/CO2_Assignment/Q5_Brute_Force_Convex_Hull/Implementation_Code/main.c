#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef struct{double x,y;} Point;
Point p[100],h[100];int n,hn=0;
double cross(Point a,Point b,Point c){return (b.x-a.x)*(c.y-a.y)-(b.y-a.y)*(c.x-a.x);}
int cmpAngle(const void *a,const void *b){Point A=*(Point*)a,B=*(Point*)b;double aa=atan2(A.y, A.x),bb=atan2(B.y,B.x);return (aa>bb)-(aa<bb);}
void hull(){int used[100]={0};for(int i=0;i<n;i++)for(int j=i+1;j<n;j++){int pos=0,neg=0;for(int k=0;k<n;k++)if(k!=i&&k!=j){double z=cross(p[i],p[j],p[k]);if(z>1e-9)pos=1;if(z< -1e-9)neg=1;}if(!(pos&&neg)){used[i]=used[j]=1;}}Point q[100];for(int i=0;i<n;i++)if(used[i])q[hn++]=p[i];double cx=0,cy=0;for(int i=0;i<hn;i++){cx+=q[i].x;cy+=q[i].y;}if(hn){cx/=hn;cy/=hn;for(int i=0;i<hn;i++){q[i].x-=cx;q[i].y-=cy;}qsort(q,hn,sizeof(Point),cmpAngle);printf("Hull boundary candidates (CCW): ");for(int i=0;i<hn;i++)printf("(%.1f,%.1f) ",q[i].x+cx,q[i].y+cy);puts("");}}
int main(){Point a[]={{0,0},{4,0},{4,4},{0,4},{2,2},{1,1},{3,2}};Point b[]={{0,0},{5,1},{6,4},{3,7},{-1,4},{2,3},{3,2},{1,2}};for(int t=0;t<2;t++){Point *src=t?b:a;n=t?8:7;for(int i=0;i<n;i++)p[i]=src[i];hn=0;printf("Dataset %d: ",t+1);hull();}return 0;}