#include <stdio.h>
void main()
{
    int n;
    printf("Enter number of process: ");
    scanf("%d", &n);

    int at[n];
    int bt[n];

    printf("Enter arrival time for each process:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &at[i]);
    }

    printf("Enter burst time for each process:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &bt[i]);
    }

    int st[n];
    int wt[n];
    int ct[n];
    int tat[n];

    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            st[0] = at[0];
            wt[0] = st[0] - at[0];
            ct[0] = st[0] + bt[0];
            tat[0] = ct[0] - at[0];
        }
        else
        {
            st[i] = ct[i - 1];
            wt[i] = st[i] + at[i];
            ct[i] = st[i] + bt[i];
            tat[i] = ct[i] - at[i];
        }
    }

    printf("P\t|\tA.T.\t|\tB.T.\t|\tS.T.\t|\tW.T.\t|\tC.T.\t|\tT.A.T.\n");
    printf("---------------------------------------------------------------------------------------------------------\n");
    for (int i = 0; i < n; i++)
    {
        printf("p%d\t|\t%d\t|\t%d\t|\t%d\t|\t%d\t|\t%d\t|\t%d\n", i + 1, at[i], bt[i], st[i], wt[i], ct[i], tat[i]);
    }
}