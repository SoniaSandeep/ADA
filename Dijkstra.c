#include <stdio.h>

#define INF 999

int main()
{
    int n;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    int cost[n][n];

    printf("Enter cost matrix:\n");
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            scanf("%d", &cost[i][j]);

            if(cost[i][j] == 0 && i != j)
                cost[i][j] = INF;
        }
    }

    int source;
    printf("Enter source vertex: ");
    scanf("%d", &source);

    int dist[n], visited[n];

    for(int i = 0; i < n; i++)
    {
        dist[i] = cost[source][i];
        visited[i] = 0;
    }

    dist[source] = 0;
    visited[source] = 1;

    for(int count = 1; count < n; count++)
    {
        int min = INF, u;

        for(int i = 0; i < n; i++)
        {
            if(!visited[i] && dist[i] < min)
            {
                min = dist[i];
                u = i;
            }
        }

        visited[u] = 1;

        for(int v = 0; v < n; v++)
        {
            if(!visited[v] && dist[u] + cost[u][v] < dist[v])
            {
                dist[v] = dist[u] + cost[u][v];
            }
        }
    }

    printf("\nShortest distances from vertex %d:\n", source);

    for(int i = 0; i < n; i++)
        printf("%d -> %d = %d\n", source, i, dist[i]);

    return 0;
}
