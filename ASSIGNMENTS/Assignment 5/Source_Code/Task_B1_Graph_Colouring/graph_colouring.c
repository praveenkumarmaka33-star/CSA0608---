/* CO5 B1: Instrumented graph colouring.
   Compile: gcc -O2 graph_colouring.c -o graph_colouring
   Input format: n m, followed by an n x n adjacency matrix.
*/
#include <stdio.h>
#include <stdlib.h>
#define MAX 30
int n, m, adj[MAX][MAX], colour[MAX], order[MAX], degree[MAX];
long long nodes, attempts, rejected, backtracks;
int maxDepth, solutionFound;

int safe(int v, int c) {
    for (int u=0; u<n; u++)
        if (adj[v][u] && colour[u] == c) return 0;
    return 1;
}
int dfs(int depth, int heuristic) {
    nodes++;
    if (depth > maxDepth) maxDepth = depth;
    if (depth == n) { solutionFound=1; return 1; }
    int v = order[depth];
    for (int c=1; c<=m; c++) {
        attempts++;
        if (safe(v,c)) {
            colour[v]=c;
            if (dfs(depth+1, heuristic)) return 1;
            colour[v]=0;
            backtracks++;
        } else rejected++;
    }
    return 0;
}
void run(int heuristic) {
    for(int i=0;i<n;i++){ colour[i]=0; order[i]=i; degree[i]=0; }
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) if(adj[i][j]) degree[i]++;
    if(heuristic) {
        /* Descending degree: most constrained/highest-conflict vertex first.
           Stable tie break: lower vertex index first. */
        for(int i=0;i<n;i++) for(int j=i+1;j<n;j++)
            if(degree[order[j]] > degree[order[i]]) {
                int t=order[i]; order[i]=order[j]; order[j]=t;
            }
    }
    nodes=attempts=rejected=backtracks=0; maxDepth=0; solutionFound=0;
    int ok=dfs(0,heuristic);
    printf("%s\n", heuristic ? "Degree-descending order" : "Input order");
    printf("Result: %s\n", ok ? "COLOURABLE" : "NOT COLOURABLE");
    printf("Search nodes: %lld\nCandidate assignments: %lld\nRejected branches: %lld\nBacktracks: %lld\nMaximum depth: %d\n",
           nodes,attempts,rejected,backtracks,maxDepth);
    if(ok) {
        printf("Colouring:");
        for(int i=0;i<n;i++) printf(" v%d=C%d",i+1,colour[i]);
        printf("\n");
    }
}
int main(void) {
    if(scanf("%d%d",&n,&m)!=2 || n<1 || n>MAX || m<1) return 1;
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) scanf("%d",&adj[i][j]);
    run(0); run(1);
    return 0;
}
