#include <stdio.h>
#include <math.h>
#define N 1000
typedef struct{double x,y;} Point;
typedef struct{int ids[N];int count;} Cell;
Cell grid[100][100];
int main(){Point p[12]={{1,1},{2,2},{3,3},{4,4},{5,5},{6,6},{7,7},{8,8},{9,9},{10,10},{11,11},{11.2,11}};int n=12;double w=3.0,best=1e100;int bi=-1,bj=-1;long brute=0,candidate=0;for(int i=0;i<n;i++)for(int j=i+1;j<n;j++){double dx=p[i].x-p[j].x,dy=p[i].y-p[j].y,d=sqrt(dx*dx+dy*dy);brute++;if(d<best)best=d,bi=i,bj=j;}printf("Original brute force: %ld distance calculations, closest distance %.4f\\n",brute,best);
for(int i=0;i<n;i++){int x=(int)(p[i].x/w),y=(int)(p[i].y/w);if(x>=0&&x<100&&y>=0&&y<100)grid[x][y].ids[grid[x][y].count++]=i;}
best=1e100;bi=bj=-1;for(int i=0;i<n;i++){int cx=(int)(p[i].x/w),cy=(int)(p[i].y/w);for(int x=cx-1;x<=cx+1;x++)for(int y=cy-1;y<=cy+1;y++)if(x>=0&&x<100&&y>=0&&y<100)for(int z=0;z<grid[x][y].count;z++){int j=grid[x][y].ids[z];if(j<=i)continue;candidate++;double dx=p[i].x-p[j].x,dy=p[i].y-p[j].y,d=sqrt(dx*dx+dy*dy);if(d<best)best=d,bi=i,bj=j;}}
printf("Grid candidate filter: %ld distance calculations, closest distance %.4f\\n",candidate,best);puts("Note: this fixed-neighbour prototype is not a universal exact guarantee; see report for safe adaptive-bound requirement.");return 0;}