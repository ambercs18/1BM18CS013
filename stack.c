#include<stdio.h>
void push(int s[100],int *t,int e);
int pop(int s[100],int *t);
void display(int s[100],int t);
void main()
{
int st[100];
int top=-1;
int x;
push(st,&top,1);
push(st,&top,2);
push(st,&top,3);
display(st,top);
x=pop(st,&top);
if(x!=-99999)
printf("The element popped is ");
display(st,top);
}
void push(int s[100],int *t,int e)
{
if(*t==99)
{
printf("Stack overflow \n");
return;
}
s[++*t]=e;
}
int pop(int s[100],int *t)
{
if(*t==-1)
{
printf("Stack Underflow");
return -99999;
}
return s[*t];
*t=*t-1;
}
void display(int s[100],int t)
{
if(t==-1)
{
printf("Empty Stack");
return;
}
for(int i=t;i>-1;i--)
printf("%d \n",s[i]);
}

