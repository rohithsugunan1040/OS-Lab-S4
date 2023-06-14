#include <stdio.h>

#define MAX_PROCESSES 10
#define MAX_RESOURCES 5

int isSafeState(int n, int m, int alloc[MAX_PROCESSES][MAX_RESOURCES], int max[MAX_PROCESSES][MAX_RESOURCES], int avail[MAX_RESOURCES])
{
    int need[MAX_PROCESSES][MAX_RESOURCES];
    int work[MAX_RESOURCES];
    int finish[MAX_PROCESSES] = {0};
    int safeSequence[MAX_PROCESSES];
    int safeIndex = 0;
    int numFinished = 0;

    // Calculate the need matrix
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }

    // Copy available resources to work array
    for (int i = 0; i < m; i++)
    {
        work[i] = avail[i];
    }

    // Find a safe sequence
    while (numFinished < n)
    {
        int found = 0;

        for (int i = 0; i < n; i++)
        {
            if (!finish[i])
            {
                int canExecute = 1;

                // Check if process can be executed
                for (int j = 0; j < m; j++)
                {
                    if (need[i][j] > work[j])
                    {
                        canExecute = 0;
                        break;
                    }
                }

                if (canExecute)
                {
                    // Execute the process
                    for (int j = 0; j < m; j++)
                    {
                        work[j] += alloc[i][j];
                    }
                    finish[i] = 1;
                    safeSequence[safeIndex++] = i;
                    numFinished++;
                    found = 1;
                }
            }
        }

        if (!found)
        {
            return 0; // System is not in a safe state
        }
    }

    // System is in a safe state
    printf("System is in a safe state\n");
    printf("Safe Sequence: ");
    for (int i = 0; i < n - 1; i++)
    {
        printf("P%d -> ", safeSequence[i]);
    }
    printf("P%d\n", safeSequence[n - 1]);

    return 1;
}

int main()
{
    int n, m;
    printf("Enter the number of Processes (up to 10): ");
    scanf("%d", &n);
    if (n <= 0 || n > MAX_PROCESSES)
    {
        printf("Invalid number of processes\n");
        return 1;
    }

    printf("Enter the number of Resources (up to 5): ");
    scanf("%d", &m);
    if (m <= 0 || m > MAX_RESOURCES)
    {
        printf("Invalid number of resources\n");
        return 1;
    }

    int alloc[MAX_PROCESSES][MAX_RESOURCES];
    int max[MAX_PROCESSES][MAX_RESOURCES];
    int avail[MAX_RESOURCES];

    printf("Enter the Allocation Matrix:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &alloc[i][j]);
            if (alloc[i][j] < 0)
            {
                printf("Invalid allocation value\n");
                return 1;
            }
        }
    }

    printf("Enter the Maximum Matrix:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &max[i][j]);
            if (max[i][j] < 0)
            {
                printf("Invalid maximum value\n");
                return 1;
            }
        }
    }

    printf("Enter the Available Resources:\n");
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &avail[i]);
        if (avail[i] < 0)
        {
            printf("Invalid available resource value\n");
            return 1;
        }
    }

    // Check if the system is in a safe state
    if (!isSafeState(n, m, alloc, max, avail))
    {
        printf("System is not in a safe state\n");
    }

    return 0;
}
