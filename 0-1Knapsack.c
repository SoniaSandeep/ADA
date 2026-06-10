#include <stdio.h>

int max(int a, int b)
{
    if(a > b)
        return a;
    return b;
}

int main()
{
    int n, W;

    printf("Enter number of items: ");
    scanf("%d", &n);

    int wt[n], profit[n];

    printf("Enter weights:\n");
    for(int i = 0; i < n; i++)
        scanf("%d", &wt[i]);

    printf("Enter profits:\n");
    for(int i = 0; i < n; i++)
        scanf("%d", &profit[i]);

    printf("Enter capacity: ");
    scanf("%d", &W);

    int dp[n+1][W+1];

    for(int i = 0; i <= n; i++)
    {
        for(int j = 0; j <= W; j++)
        {
            if(i == 0 || j == 0)
                dp[i][j] = 0;

            else if(wt[i-1] <= j)
            {
                dp[i][j] = max(
                    profit[i-1] + dp[i-1][j-wt[i-1]],
                    dp[i-1][j]
                );
            }

            else
            {
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    printf("Maximum Profit = %d\n", dp[n][W]);

    return 0;
}
