/*
Write a program to demonstrate page replacement algorithm using First In First Out
*/




#include<stdio.h>
int main()
{

	int reference_string[20],page_faults = 0,s,pages,frames;
	printf("Enter total number of pages\t");			//accept the total number of pages present in the refernce string
	scanf("%d",&pages);
	printf("Enter values of reference strings\n");			//accept the pages which are present in the reference string
	for(int i=0;i<pages;i++)
	{
		printf("Value no.%d\t",i+1);
		scanf("%d",&reference_string[i]);
	}
	printf("Enter the total number of frames\n");			//accept the total number of frames present 
	scanf("%d",&frames);
	int temp[frames];
	for(int i=0;i<frames;i++)
	{
		temp[i]=-1;
	}
	for(int i=0;i<pages;i++)
	{	
		s=0;
		for(int j=0;j<frames;j++)
		{
			if(reference_string[i]==temp[j])
			{
				s++;
				page_faults --;
			}
		}
		page_faults ++;
		if(page_faults<frames && s==0)
		{
			temp[i]=reference_string[i];
		}
		else if(s==0)
		{
			temp[(page_faults-1)%frames]=reference_string[i];
		}
		printf("\n");
		for(int j=0;j<frames;j++)
		{
			printf("%d\t",temp[j]);	
		}
		if(s==0)
		{
			printf("\t*");
		}
	}
	printf("\nTotal page faults\t%d\n",page_faults);
	return 0;
}



/*
OUTPUT -

harsh@harsh-HP-ProBook-440-G4:~$ gcc paging_fifo.c
harsh@harsh-HP-ProBook-440-G4:~$ ./a.out
Enter total number of pages	13
Enter values of reference strings
Value no.1	1
Value no.2	2
Value no.3	3
Value no.4	4
Value no.5	1
Value no.6	2
Value no.7	4
Value no.8	3
Value no.9	2
Value no.10	1
Value no.11	2
Value no.12	3
Value no.13	2
Enter the total number of frames
3

1	-1	-1		*
1	2	-1		*
1	2	3		*
4	2	3		*
4	1	3		*
4	1	2		*
4	1	2	
3	1	2		*
3	1	2	
3	1	2	
3	1	2	
3	1	2	
3	1	2	
Total page faults	7
harsh@harsh-HP-ProBook-440-G4:~$ 

*/
