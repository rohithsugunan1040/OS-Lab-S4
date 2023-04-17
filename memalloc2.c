#include<stdio.h>
 

void bestFit(int blockSize[], int m, int processSize[], int n)
{
    // Stores block id of the block allocated to a process
    int allocation[n];
 
    // Initially no block is assigned to any process
    for (int i = 0; i < n; i++)
        allocation[i] = -1;
 
    // pick each process and find suitable blocks
    // according to its size ad assign to it
    for (int i = 0; i < n; i++)
    {
        // Find the best fit block for current process
        int bestIdx = -1;
        for (int j = 0; j < m; j++)
        {
            if (blockSize[j] >= processSize[i])
            {
                if (bestIdx == -1)
                    bestIdx = j;
                else if (blockSize[bestIdx] > blockSize[j])
                    bestIdx = j;
            }
        }
 
        // If we could find a block for current process
        if (bestIdx != -1)
        {
            // allocate block j to p[i] process
            allocation[i] = bestIdx;
 
            // Reduce available memory in this block.
            blockSize[bestIdx] -= processSize[i];
        }
    }
 
    printf("\nProcess No.\tProcess Size\tBlock no.\n");
    for (int i = 0; i < n; i++)
    {
        printf(" %d\t\t%d\t\t", i+1, processSize[i]);
        if (allocation[i] != -1)
            printf("%d", allocation[i] + 1);
        else
            printf("Not Allocated");
        printf("\n");
    }
}

int main()
{
   printf(" | Best Fit |\n\n\n");
    int n,p,m;
    printf("enter the no of blocks ");
    scanf("%d",&n);
    printf("enter the no of processes ");
    scanf("%d",&p);
    printf("enter block size\n");
    int blocksize[n],processsize[p];
    for(int i=0;i<n;i++)
    {
        printf("enter sizeof block %d",i+1);
        scanf("%d",&blocksize[i]);
    }
    printf("enter process size \n");
    for(int i=0;i<p;i++)
    {
        printf("enter sizeof process %d",i+1);
        scanf("%d",&processsize[i]);
    }
    m=sizeof(blocksize)/sizeof(blocksize[0]);
    n=sizeof(processsize)/sizeof(processsize[0]);
    bestFit(blocksize,m,processsize,n);
 
    return 0 ;
}
