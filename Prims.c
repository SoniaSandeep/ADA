#include <stdio.h>

#define INF 999

int main() {
    int n;

    printf("Enter number of vertices: ");
    scanf("%d",&n);

    int G[n][n];

    printf("Enter adjacency matrix:\n");

    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            scanf("%d",&G[i][j]);

    int selected[n];
    for(int i=0;i<n;i++)
        selected[i]=0;

    selected[0]=1;

    int edge=0,total=0;

    printf("\nMST Edges:\n");

    while(edge<n-1) {
        int min=INF;
        int x=0,y=0;

        for(int i=0;i<n;i++) {
            if(selected[i]) {
                for(int j=0;j<n;j++) {
                    if(!selected[j] && G[i][j]) {
                        if(G[i][j]<min) {
                            min=G[i][j];
                            x=i;
                            y=j;
                        }
                    }
                }
            }
        }

        printf("%d - %d : %d\n",x,y,min);

        total += min;
        selected[y]=1;
        edge++;
    }

    printf("Minimum Cost = %d\n",total);

    return 0;
}
