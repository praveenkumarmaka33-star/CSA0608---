#include <stdio.h>

#define V 5
#define INF 1000000000

int main(void) {
    const char *name[V] = {"A", "B", "C", "D", "E"};
    int w[V][V] = {
        {0, 4, 7, INF, INF},
        {INF, 0, 2, 6, INF},
        {INF, INF, 0, 1, 8},
        {INF, INF, INF, 0, 3},
        {INF, INF, INF, INF, 0}
    };
    int dist[V], pred[V], used[V] = {0};

    /* Dijkstra from A: valid because all given weights are non-negative. */
    for (int i = 0; i < V; i++) { dist[i] = INF; pred[i] = -1; }
    dist[0] = 0;

    for (int step = 0; step < V; step++) {
        int u = -1;
        for (int i = 0; i < V; i++)
            if (!used[i] && (u == -1 || dist[i] < dist[u])) u = i;
        if (u == -1 || dist[u] == INF) break;
        used[u] = 1;
        for (int v = 0; v < V; v++) {
            if (w[u][v] < INF && !used[v] && dist[u] + w[u][v] < dist[v]) {
                dist[v] = dist[u] + w[u][v];
                pred[v] = u;
            }
        }
    }

    printf("Dijkstra shortest distances from A:\n");
    for (int i = 0; i < V; i++)
        printf("A to %s = %d\n", name[i], dist[i]);

    /* Bellman-Ford core on the same graph. */
    int bf[V];
    for (int i = 0; i < V; i++) bf[i] = INF;
    bf[0] = 0;
    for (int pass = 1; pass < V; pass++)
        for (int u = 0; u < V; u++)
            for (int v = 0; v < V; v++)
                if (w[u][v] < INF && bf[u] < INF && bf[u] + w[u][v] < bf[v])
                    bf[v] = bf[u] + w[u][v];

    int negativeCycle = 0;
    for (int u = 0; u < V; u++)
        for (int v = 0; v < V; v++)
            if (w[u][v] < INF && bf[u] < INF && bf[u] + w[u][v] < bf[v])
                negativeCycle = 1;
    printf("Bellman-Ford reachable negative cycle: %s\n", negativeCycle ? "YES" : "NO");

    /* Floyd-Warshall all-pairs shortest paths. */
    int d[V][V];
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++) d[i][j] = w[i][j];

    for (int k = 0; k < V; k++)
        for (int i = 0; i < V; i++)
            for (int j = 0; j < V; j++)
                if (d[i][k] < INF && d[k][j] < INF && d[i][k] + d[k][j] < d[i][j])
                    d[i][j] = d[i][k] + d[k][j];

    printf("Floyd-Warshall distance matrix (INF = unreachable):\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++)
            if (d[i][j] >= INF) printf("%5s", "INF");
            else printf("%5d", d[i][j]);
        printf("\n");
    }
    return 0;
}
