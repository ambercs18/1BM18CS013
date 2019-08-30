
#include<stdio.h>
void insert(int q[],int bt[],int *r,int *rt,int p,int t)
{
	if(*r==4)
	{
		printf("Queue Overflow");
		return;
	}
	*r=*r+1;
	q[*r]=p;
	if(*rt==4)
	{
		printf("Queue Overflow");
		return;
	}
	*rt=*rt+1;
	bt[*rt]=t;
	
}
int pdelete(int q[],int *f,int*r)
{
	int e;
	if(*f>*r)
	{
		printf("QF");
		return -23467;
	}
	e=q[*f];
	*f=*f-1;
	return e;	
}
int tdelete(int bt[],int *ft,int*rt)
{
	int e;
	if(*ft>*rt)
	{
		printf("QF");
		return -23467;
	}
	e=bt[*ft];
	*ft=*ft-1;
	return e;	
}
void main()
{
	int f,ft=0;
	int r,rt=-1;
	int q[5];
	int bt[5];
	int ch,ch1;
	int s=0;
	do
	{
		ch=0;
		printf("Enter 1 to enter process and time \n Enter 2 to display \n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("Enter process no. and time taken");
				int p,t;
				scanf("%d%d",&p,&t);
				insert(q,bt,&r,&rt,p,t);
				break;
				case 2:
					for(int j=0;j<2;j++)
					{
						printf("Process %d takes %d time \n",pdelete(q,&f,&r),s+tdelete(bt,&ft,&rt));
					}
					break;
		}
		printf("Enter 1 to continue and 0 exit");
		scanf("%d",&ch1);
	
	}while(ch1!=0);
}
