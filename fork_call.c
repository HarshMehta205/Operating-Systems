/*
write a program using fork to create a child process . The parent process should sort elements in ascending order and child process should sort elements in descending order.
*/


#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
void asc(int a[10],int size)
{
		int temp;
		for(int k=0;k<size;k++)
		{
			for(int j=k+1;j<size;j++)
			{
				if(a[k]>a[j])
				{
					temp=a[k];
					a[k]=a[j];
					a[j]=temp;
				}
				
			}
			
		}
		for(int i=0;i<size;i++)
		{
			printf("%d\t",a[i]);
		}	
		printf("\t");

}

void dsc(int a[10],int size)
{
		int temp;
		for(int k=0;k<size;k++)
		{
			for(int j=k+1;j<size;j++)
			{
				if(a[k]<a[j])
				{
					temp=a[k];
					a[k]=a[j];
					a[j]=temp;
				}
				
			}
		}
		for(int i=0;i<size;i++)
		{
			printf("%d\t",a[i]);
		}	

}
int main()
{
	int a[10],size;
	pid_t mypid;
	printf("Enter array size\n");
	scanf("%d",&size);
	
	printf("Enter array elements");
	for(int i=0;i<size;i++)
	{
		scanf("%d",&a[i]);
	}
	
	mypid=fork();
	if(mypid==0)
	{
		/* CHILD PROCESS*/
		asc(a,size);
	}
	else
	{	/*PARENT PROCESS*/
		dsc(a,size);
	}

	return 0;
}
