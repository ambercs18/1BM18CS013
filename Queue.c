#define size 3
#include<stdio.h>
void insert(int e,int *r,int q[])
{
if(*r==size-1)
{
printf("Qf");
return;
}
*r+=1;
q[*r]=e;
}
int del(int q[],int *f,int *r)
{
int e;
if(*f>*r)
{
printf("Queue Underflow\n");
return -9889;
}
e=q[*f];
*f+=1;
return e;
}
void display(int q[],int f,int r)
{
if(f>r)
{
printf("Queue Empty\n");
return;
}
printf("Contents of Queue are\n");
for(int i=f;i<=r;i++)
printf("%d\n",q[i]);
}
void main()
{
int f=0,r=-1,ch,ch1,e;
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
insert(e,&r,q);
break;
case 2:
printf("The deleted element is %d\n",del(q,&f,&r));
break;
case 3:
display(q,f,r);
break;
}
printf("Enter 1 to continue and 0 to exit\n");
scanf("%d",&ch1);
}while(ch1!=0);
}


