/*

Write a C program using POSIX threads(pthreads) to perfrom arthmetic operation
*/

/*
pthread_create(pthread_t *tid,const pthread_attr_t *attr,void *(*func)(void*),void *arg)

pthread_join(pthread_t tid,void ** status)



*/

#include<stdio.h>
#include<pthread.h>


struct number
{
	int num1;
	int num2;
};

typedef struct number num;

void * display_num(void * );
void * display_add(void * );
void * display_sub(void * );
void * display_mul(void * );
void * display_div(void * );


int main()
{
	num n;
	pthread_t tid1,tid2,tid3,tid4,tid5;
	
	printf("enter a numbers: \n");
	scanf("%d",&n.num1);
	scanf("%d",&n.num2);
	
	pthread_create(&tid1,NULL,display_num,(void*)&n);
	pthread_join(tid1,NULL);
	pthread_create(&tid2,NULL,display_add,(void*)&n);
	pthread_join(tid2,NULL);
	pthread_create(&tid3,NULL,display_sub,(void*)&n);
	pthread_join(tid3,NULL);
	pthread_create(&tid4,NULL,display_mul,(void*)&n);
	pthread_join(tid4,NULL);
	pthread_create(&tid5,NULL,display_div,(void*)&n);
	pthread_join(tid5,NULL);
	return 0;
}



void * display_num(void * n)
{
	num *x=(num *)n;
	printf("displaying the numbers \n");
	printf("numbers are : %d \t %d \n",x->num1,x->num2);	
	return NULL;
}



void * display_add(void * n)
{
	int result;
	num *x=(num *)n;
	printf("\ndisplaying addition of numbers \n");
	result=x->num1+x->num2;	
	printf("addition is : %d",result);
	return NULL;
}

void * display_sub(void * n)
{
	int result;
	num *x=(num *)n;
	printf("\ndisplaying subraction of numbers \n");
	result=x->num1-x->num2;	
	printf("addition is : %d",result);	
	return NULL;
}

void * display_mul(void * n)
{
	int result;
	num *x=(num *)n;
	printf("\ndisplaying mulpication of numbers \n");
	result=x->num1*x->num2;	
	printf("mulpication is : %d",result);	
	return NULL;
}

void * display_div(void * n)
{
	float result;
	num *x=(num *)n;
	printf("\ndisplaying divison of numbers \n");
	result=(float)x->num1/x->num2;	
	printf("divison is : %f \n",result);	
	return NULL;
}


/*
output-
ibm@IBM:~$ gcc -o finalthread finalthread.c -lpthread
ibm@IBM:~$ ./finalthread
enter a numbers: 
5
3
displaying the numbers 
numbers are : 5 	 3 

displaying addition of numbers 
addition is : 8
displaying subraction of numbers 
addition is : 2
displaying mulpication of numbers 
mulpication is : 15
displaying divison of numbers 
divison is : 1.666667 
ibm@IBM:~$ 

*/
