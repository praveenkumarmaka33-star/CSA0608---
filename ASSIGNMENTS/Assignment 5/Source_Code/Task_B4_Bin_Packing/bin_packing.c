/* CO5 B4: First-Fit Decreasing bin packing heuristic.
   Sort workloads descending, then place each in the first server with room.
   Compile: gcc -O2 bin_packing.c -o bin_packing
*/
#include <stdio.h>
#include <stdlib.h>
#define MAX 10000
typedef struct { int load, items[MAX/10], count; } Bin;
int cmp(const void *a,const void *b){int x=*(const int*)a,y=*(const int*)b;return (y>x)-(y<x);}
int main(void){
    int n,capacity,w[MAX];
    if(scanf("%d%d",&n,&capacity)!=2 || n<1 || n>MAX || capacity<=0) return 1;
    for(int i=0;i<n;i++){scanf("%d",&w[i]);if(w[i]<=0||w[i]>capacity)return 1;}
    qsort(w,n,sizeof(int),cmp);
    Bin *bins=calloc(n,sizeof(Bin)); int used=0;
    for(int i=0;i<n;i++){
        int b;
        for(b=0;b<used;b++) if(bins[b].load+w[i]<=capacity) break;
        if(b==used) used++;
        bins[b].load+=w[i]; bins[b].items[bins[b].count++]=w[i];
    }
    printf("First-Fit Decreasing result\nServers used: %d\n",used);
    for(int b=0;b<used;b++){
        printf("Server %d: ",b+1);
        for(int j=0;j<bins[b].count;j++) printf("%d ",bins[b].items[j]);
        printf("| Used=%d | Remaining=%d\n",bins[b].load,capacity-bins[b].load);
    }
    free(bins); return 0;
}
