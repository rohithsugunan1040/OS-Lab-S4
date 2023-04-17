#include<stdio.h>
#include<string.h>

void worstFit(int blockSize[], int m, int processSize[], int n)
{
int allocation[n];
memset(allocation, -1, sizeof(allocation));
int i, j, wstIdx;


for (i = 0; i < n; i++)
{
    wstIdx = -1;
    for (j = 0; j < m; j++)
    {
        if (blockSize[j] >= processSize[i])
        {
            if (wstIdx == -1)
                wstIdx = j;
            else if (blockSize[wstIdx] < blockSize[j])
                wstIdx = j;
        }
    }

    if (wstIdx != -1)
    {
        allocation[i] = wstIdx;
        blockSize[wstIdx] -= processSize[i];
    }
}

printf("\nProcess No.\tProcess Size\tBlock no.\n");
for (i = 0; i < n; i++)
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
printf(" | Worst  Fit |\n\n\n");
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
worstFit(blocksize, m, processsize, n);

return 0 ;

}