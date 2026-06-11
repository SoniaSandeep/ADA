#include <stdio.h>

int main()
{
    int n;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    int graph[n][n];

    printf("Enter adjacency matrix:\n");
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            scanf("%d",&graph[i][j]);

    int indegree[n];

    for(int i=0;i<n;i++)
    {
        indegree[i]=0;

        for(int j=0;j<n;j++)
        {
            if(graph[j][i]==1)
                indegree[i]++;
        }
    }

    printf("Topological Order: ");

    for(int k=0;k<n;k++)
    {
        int source = -1;

        for(int i=0;i<n;i++)
        {
            if(indegree[i]==0)
            {
                source=i;
                break;
            }
        }

        printf("%d ", source);

        indegree[source] = -1;

        for(int j=0;j<n;j++)
        {
            if(graph[source][j]==1)
                indegree[j]--;
        }
    }

    return 0;
}
