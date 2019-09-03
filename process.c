#define SIZE 10
#include<stdio.h>
#include<stdlib.h>
void insert(int item, int *top,int Bt[SIZE])
{
    if(*top==SIZE-1)
      {
        printf("queue overflow");
        return;
      }
      *top=*top+1;
      Bt[*top]=item;
}
void push(int pro[10],int ele,int *r)
{
    pro[++(*r)]=ele;
}
int delete(int *f,int *r,int pro[10])
{
    int item;
  if(*f>*r)
  {
      printf("queue underflow");
      return -9999;
  }
  item=pro[*f];
  *f=*f+1;
  return item;
}
int del(int *s,int *top,int Bt[10])
{
  int item;
  if(*s>*top)
  {
      printf("Queue underflow");
      return -9999;
  }
  item=Bt[*s];
  *s=*s+1;
  return item;
}
void display(int Bt[SIZE],int pro[10],int top,int s,int f,int r)
{
    int i,j,sum=0,z=0;
    if(f>r)
    {
        printf("queue is empty");
        return;
    }
   for(i=f;i<=r;i++)
   {
       if(i==0)
        printf("The process with process id %d starts at 0 and ends at %d seconds\n",pro[i],Bt[i]);
       else
       {
           for(j=0;j<=i;j++)
            {
                sum=sum+Bt[j];
            }
           printf("The process with process id %d starts at %d and ends at %d seconds\n",pro[i],(sum-Bt[j-1]),sum);
       }
       sum=0;
   }
}
void main()
{
    int f=0,r=-1,choice,ch,Bt[SIZE],x,y,top=-1,s=0;
    int pro[100];
    while(1)
    {
        printf("Enter the operation to be performed on queue:\n1.Insert a process in the queue\n2.Delete a process from the queue\n3.Display the queue schedule\nEnter 4 to exit\n");
    scanf("%d",&choice);
        switch(choice)
        {
        case 1:printf("The process will be pushed into the queue\nEnter the process id");
            scanf("%d",&y);
            push(pro,y,&top);
            printf("enter the time required to complete the process");
            scanf("%d",&x);
            insert(x,&r,Bt);
            break;
        case 2:
            x=delete(&f,&r,pro);
            printf("Process with process id %d is deleted\n",x);
            y=del(&s,&top,Bt);
            printf("The process deleted has Burst time of %d seconds\n",y);
            break;
        case 3:
            display(Bt,pro,top,s,f,r);
            break;
        case 4:
            exit(1);
        default:
            printf("wrong choice\n");
            break;
        }

    }
}
