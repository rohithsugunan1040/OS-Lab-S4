#include<stdio.h>

void firstfit(int blocksize[],int processize[],int processes,int blocks)
{
    int allocate[processes];
    int i,j;

    for( i=0;i<processes;i++)
    {
        allocate[i]=-1;
    }
    for(i=0;i<processes;i++)
    {
        for(j=0;j<blocks;j++)
        {
            if(blocksize[j]>=processize[i])
            {
                allocate[i]=j;
                blocksize[j]-=processize[i];
            }
            break;
        }
    }
    printf("process no\tprocess size\tblockno\n");
    for(i=0;i<processes;i++)
    {
         printf("%d \t\t\t %d \t\t\t", i+1,processize[i]);
	        if (allocate[i] != -1)
	            printf("%d\n",allocate[i] + 1);
	        else
	            printf("Not Allocated\n");
	    }
	
    }

void main()
{
    printf(" | FIRST FIT |\n\n\n");
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
    firstfit(blocksize,processsize,n,m);
    

}
