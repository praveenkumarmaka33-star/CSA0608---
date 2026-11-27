#include <stdio.h>
#include <math.h>
typedef struct{double x,y;} Point;
void closest(Point p[],int n){double best=1e100;int bi=-1,bj=-1;long pairs=0;for(int i=0;i<n-1;i++)for(int j=i+1;j<n;j++){double dx=p[i].x-p[j].x,dy=p[i].y-p[j].y,d=sqrt(dx*dx+dy*dy);pairs++;if(d<best){best=d;bi=i;bj=j;}}printf("Points=%d pairs=%ld distance calculations=%ld\\n",n,pairs,pairs);if(bi>=0)printf("Closest: (%g,%g) and (%g,%g), distance=%.4f\\n",p[bi].x,p[bi].y,p[bj].x,p[bj].y,best);}
int main(){Point a[]={{0,0},{3,4},{1,1},{8,8},{2,2}};Point b[]={{0,0},{10,10},{20,20},{21,20},{-10,-10},{3,4},{2,2},{100,100}};Point c[]={{0,0},{100,100},{200,200},{300,300},{400,400},{500,500},{600,600},{700,700},{800,800},{801,800},{900,900},{1000,1000}};closest(a,5);closest(b,8);closest(c,12);return 0;}