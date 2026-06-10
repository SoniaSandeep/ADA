#include <stdio.h>

int main()
{
    int n = 3;

    int p[10];
    int dir[10];

    for(int i = 0; i < n; i++)
    {
        p[i] = i + 1;
        dir[i] = -1;   // left
    }

    int total = 1;
    for(int i = 1; i <= n; i++)
        total *= i;

    for(int count = 0; count < total; count++)
    {
        for(int i = 0; i < n; i++)
            printf("%d", p[i]);
        printf("\n");

        int mobile = 0;
        int pos = -1;

        for(int i = 0; i < n; i++)
        {
            if(dir[i] == -1 && i > 0 &&
               p[i] > p[i-1] && p[i] > mobile)
            {
                mobile = p[i];
                pos = i;
            }

            if(dir[i] == 1 && i < n-1 &&
               p[i] > p[i+1] && p[i] > mobile)
            {
                mobile = p[i];
                pos = i;
            }
        }

        if(pos == -1)
            break;

        int newPos = pos + dir[pos];

        int temp = p[pos];
        p[pos] = p[newPos];
        p[newPos] = temp;

        temp = dir[pos];
        dir[pos] = dir[newPos];
        dir[newPos] = temp;

        for(int i = 0; i < n; i++)
        {
            if(p[i] > mobile)
                dir[i] *= -1;
        }
    }

    return 0;
}
