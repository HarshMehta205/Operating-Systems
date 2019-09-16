/*
to perform a C program to simuate Bankers Algorithm for deadlock avoidance
*/

#include<stdio.h>

void isSafe(int n,int m,int avail[20],int need[20][20],int alloc[20][20])
{
    int i,j,finish[20],work[20],flag,seq[20],k=0;
    for(i=0;i<n;i++)
    {
        finish[i]=0;
    }
    for(j=0;j<m;j++)
    {
        work[j]=avail[j];
    }
    while(1)
    {
        flag=0;
        for(i=0;i<n;i++)
        {
            if(finish[i]==0)
            {
                for(j=0;j<m;j++)
                {
                    if(need[i][j]>work[j])break;
                }
                if(j==m)
                {
                    flag=1;
                    finish[i]=1;
                    seq[k]=i;
                    k++;
                    for(j=0;j<m;j++)
                    {
                        work[j]=work[j]+alloc[i][j];
                    }
                }
            }
        }
        if (flag==0 || k==n)break;
    }
    if(k==n)
    {
        printf("System is in safe state\n");
        for(i=0;i<n;i++)
        {
            printf("P %d\t",seq[i]);
        }
        
    }
    else
    {
        printf("System is in unsafe state\n");
        
    }
}

void readMatrix(int n,int m,int matrix[20][20])
{
    int i,j;
    for(i=0;i<n;i++)
    {   
       printf("For process P%d\n",i);
        for(j=0;j<m;j++)
        {
            printf(" R%d ",j);
            scanf("%d",&matrix[i][j]);
        }
    }
}

void printMatrix(int n,int m,int matrix[20][20])
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            printf("%d\t",matrix[i][j]);
        }
        printf("\n");
    }
}

void readVector(int m,int max_avail[20])
{
    int i;
    for(i=0;i<m;i++)
    {   
        printf(" R%d ",i);
        scanf("%d",&max_avail[i]);
    }
}

void printVector(int m,int max_avail[20])
{
    int i;
    for(i=0;i<m;i++)
    {
        printf("%d\t",max_avail[i]);
    }
    printf("\n");
}

void comp_need(int n,int m,int need[20][20],int alloc[20][20],int max_claim[20][20])
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            need[i][j]=max_claim[i][j]-alloc[i][j];
        }
    }
}

void comp_avail(int n,int m,int alloc[20][20],int max_avail[20])
{
    int i,j,sum;
    for(j=0;j<m;j++)
    {
        sum=0;
        for(i=0;i<n;i++)
        {
            sum=sum+alloc[i][j];
        }
        max_avail[j]=max_avail[j]-sum;
    }
}


void main()
{
    int max_avail[20],avail[20],alloc[20][20],max_claim[20][20],need[20][20],n,m;
    printf("Enter number of processes :\n");
    scanf("%d",&n);
    printf("Enter the number of resource types :\n");
    scanf("%d",&m);
    printf("Enter max instances of each resource types :\n");
    readVector(m,max_avail);
    printf("Enter max claim matrix :\n");
    readMatrix(n,m,max_claim);
    printf("Enter allocation matrix :\n");
    readMatrix(n,m,alloc);
    comp_need(n,m,need,alloc,max_claim);
    comp_avail(n,m,alloc,max_avail);
    printf("Current snapshot is :\n");
    printf("Available instances of resources :\n");
    printVector(m,max_avail);
    printf("Allocation matrix is :\n");
    printMatrix(n,m,alloc);
    printf("Maximum claim matrix is :\n");
    printMatrix(n,m,max_claim);
    printf("Need matrix is :\n");
    printMatrix(n,m,need);
    isSafe(n,m,max_avail,need,alloc);
    
}      
