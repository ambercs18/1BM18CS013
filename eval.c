#include<stdio.h>
#include<string.h>
void push(int s[100],int *t,int a)
{
if(*t==99)
printf("SF");
else
{
*t=*t+1;
s[*t]=a;
}
}
int pop(int s[100],int *t)
{
int e;
if(*t==-1)
{
printf("SE");
return -34567;
}
else
{
e=s[*t];
*t=*t-1;
return e;
}
}
int val(int a,int b,char x)
{
switch(x)
{
case '+':
return a+b; 
break;
case '-':
return a-b;
break;
case '*':
return a*b;
break;
case '/':
return a/b;
break;
}
}
void main()
{
char ch[100];
int st[100];
int top=-1;
printf("Enter Expression");
scanf("%s",ch);
ch[strlen(ch)]='\0';
int i=0;
while(ch[i]!='\0')
{
int a=0;
int b=0;
int c=0;
if(ch[i]>=48 && ch[i]<=57)
push(st,&top,(ch[i]-48));
else
{
a=pop(st,&top);
b=pop(st,&top);
c=val(b,a,ch[i]);
push(st,&top,c);
}
i++;
}
printf("%d",pop(st,&top));
}
