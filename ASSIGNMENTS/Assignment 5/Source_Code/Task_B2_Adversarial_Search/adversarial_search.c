/* CO5 B2: Compare two same-size, same-colour-count graph instances.
   Run: gcc -O2 adversarial_search.c -o adversarial_search && ./adversarial_search
   Both graphs have 8 vertices and 3 colours. Graph A is a path (easy);
   Graph B is K4 plus four vertices connected to all K4 vertices (hard/impossible
   with 3 colours due to the K4 core). */
#include <stdio.h>
#define MAX 20
int n=8, m=3, a[MAX][MAX], colour[MAX], order[MAX];
long long nodes, attempts, rejected, backs;
int safe(int v,int c,int g[MAX][MAX]){
    for(int u=0;u<n;u++) if(g[v][u] && colour[u]==c) return 0;
    return 1;
}
int dfs(int d,int g[MAX][MAX]){
    nodes++;
    if(d==n) return 1;
    int v=order[d];
    for(int c=1;c<=m;c++){
        attempts++;
        if(safe(v,c,g)){
            colour[v]=c;
            if(dfs(d+1,g)) return 1;
            colour[v]=0; backs++;
        } else rejected++;
    }
    return 0;
}
void run(char *name,int g[MAX][MAX]){
    for(int i=0;i<n;i++){colour[i]=0;order[i]=i;}
    nodes=attempts=rejected=backs=0;
    int ok=dfs(0,g);
    printf("%s: %s\nNodes=%lld Attempts=%lld Rejected=%lld Backtracks=%lld\n",
      name,ok?"COLOURABLE":"NOT COLOURABLE",nodes,attempts,rejected,backs);
}
int main(void){
    int A[MAX][MAX]={{0}},B[MAX][MAX]={{0}};
    /* Graph A: path */
    for(int i=0;i<7;i++) A[i][i+1]=A[i+1][i]=1;
    /* Graph B: K4 on vertices 1..4, plus vertices 5..8 adjacent to all core vertices.
       This has a K4 clique, so it cannot be coloured with 3 colours. */
    for(int i=0;i<4;i++) for(int j=0;j<4;j++) if(i!=j) B[i][j]=1;
    for(int i=4;i<8;i++) for(int j=0;j<4;j++) B[i][j]=B[j][i]=1;
    run("Graph A (8-vertex path)",A);
    run("Graph B (K4 core with four attached vertices)",B);
    return 0;
}
