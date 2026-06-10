#include <stdio.h>

struct Edge {
    int u, v, w;
};

int parent[10];

int find(int i)
{
    while(parent[i] != i)
        i = parent[i];
    return i;
}

void Union(int a, int b)
{
    parent[a] = b;
}

int main()
{
    int n, e;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &e);

    struct Edge edge[e];

    printf("Enter u v weight:\n");
    for(int i=0;i<e;i++)
        scanf("%d%d%d",
              &edge[i].u,
              &edge[i].v,
              &edge[i].w);

    /* Sort edges by weight */
    for(int i=0;i<e-1;i++)
    {
        for(int j=0;j<e-i-1;j++)
        {
            if(edge[j].w > edge[j+1].w)
            {
                struct Edge temp = edge[j];
                edge[j] = edge[j+1];
                edge[j+1] = temp;
            }
        }
    }

    for(int i=0;i<n;i++)
        parent[i] = i;

    int count = 0;
    int cost = 0;

    printf("\nEdges in MST:\n");

    for(int i=0; i<e && count<n-1; i++)
    {
        int a = find(edge[i].u);
        int b = find(edge[i].v);

        if(a != b)
        {
            printf("%d - %d : %d\n",
                   edge[i].u,
                   edge[i].v,
                   edge[i].w);

            cost += edge[i].w;
            Union(a,b);
            count++;
        }
    }

    printf("Minimum Cost = %d\n", cost);

    return 0;
}
