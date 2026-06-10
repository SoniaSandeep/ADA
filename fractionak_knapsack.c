#include <stdio.h>

struct Item
{
    int profit;
    int weight;
    float ratio;
};

int main()
{
    int n, capacity;

    printf("Enter number of items: ");
    scanf("%d", &n);

    struct Item item[n];

    for(int i = 0; i < n; i++)
    {
        printf("Profit and Weight of item %d: ", i + 1);
        scanf("%d %d", &item[i].profit, &item[i].weight);

        item[i].ratio = (float)item[i].profit / item[i].weight;
    }

    printf("Enter knapsack capacity: ");
    scanf("%d", &capacity);

    /* Sort by ratio in descending order */
    for(int i = 0; i < n - 1; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            if(item[j].ratio > item[i].ratio)
            {
                struct Item temp = item[i];
                item[i] = item[j];
                item[j] = temp;
            }
        }
    }

    float totalProfit = 0;

    for(int i = 0; i < n; i++)
    {
        if(capacity >= item[i].weight)
        {
            totalProfit += item[i].profit;
            capacity -= item[i].weight;
        }
        else
        {
            totalProfit += item[i].ratio * capacity;
            break;
        }
    }

    printf("Maximum Profit = %.2f\n", totalProfit);

    return 0;
}
