#define size 3
#include<stdio.h>
void insert(int e,int *r,int q[],int *f)
{
if((*f==*r+1)||(*f==0&& *r==size-1))
{
printf("Queue full\n");
return;
}
if(*f==-1)
*f=0;
*r=(*r+1)%size;
q[*r]=e;
}
int del(int q[],int *f,int *r)
{
int e;
if(*f==-1)
{
printf("Queue Underflow\n");
return -98786;
}
else
{
e=q[*f];
if(*f==*r)
{
*f=-1;
*r=-1;
*f=((*r+1)%size);
}
else
*f=((*f+1)%size);
return e;
}
}
void display(int q[],int r,int f)
{
int i;
if(f==-1)
printf("Queue Empty\n");
else
for(i=f;i!=r;i=(i+1)%size)
{
printf("%d\n",q[i]);
}
printf("%d\n",q[i]);
}
void main()
{
int f=-1,r=-1,ch,ch1,e;
int q[size];
do
{
printf("Enter 1 to insert element in queue\nEnter 2 to delete the front element\nEnter 3 to display\n");
scanf("%d",&ch);
switch(ch)
{
case 1:
printf("Enter element to insert\n");
scanf("%d",&e);
insert(e,&r,q,&f);
break;
case 2:
printf("The deleted element is %d\n",del(q,&f,&r));
break;
case 3:
display(q,r,f);
break;
}
printf("Enter 1 to continue and 0 to exit\n");
scanf("%d",&ch1);
}while(ch1!=0);
}



