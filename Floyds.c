#include <stdio.h>

#define INF 999

int main()
{
    int n;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    int cost[n][n];

    printf("Enter cost matrix:\n");

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&cost[i][j]);

            if(cost[i][j]==0 && i!=j)
                cost[i][j]=INF;
        }
    }

    for(int k=0;k<n;k++)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(cost[i][k] + cost[k][j] < cost[i][j])
                {
                    cost[i][j] = cost[i][k] + cost[k][j];
                }
            }
        }
    }

    printf("\nShortest Path Matrix:\n");

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            printf("%4d",cost[i][j]);

        printf("\n");
    }

    return 0;
}
