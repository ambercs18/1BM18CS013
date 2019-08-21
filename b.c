##include<stdio.h>
int pre(char c)
{
if(c=='/'||c=='*')
return 2;
else if(c=='+'||c=='-')
return 1;
else
return 0;
}
void push(char s[100],int *t,char c)
{
if(*t==99)
printf("SF");
else
{
*t=*t+1;
s[*t]=c;
}
}
char pop(char s[100],int *t)
{
	char e;
if(*t==-1)
{
printf("SE");
return '@';
}
else
{
 e=s[*t];
*t=*t-1;
return e;
}
}
void display(char s[100],int *t)
{
if(*t==-1)
printf("SE");
else
{
for(int i=*t;i>=0;i--)
{
if(s[i]!='('&&s[i]!=')')
printf("%c",s[i]);
}
}
}
void main()
{
char s[100],st[100];
int top=-1;
int n;
char a,m;
int k;
scanf("%d",&n);
for(int i=0;i<n;i++)
{
scanf("%c",&st[i]);
if(st[i]>=97&&st[i]<123)
printf("%c",st[i]);
else if(st[i]=='(')
push(s,&top,st[i]);
else if(st[i]==')')
{
	k=top;
	if(s[k]!='(' && top>=0)
		{
a=pop(s,&top);
printf("%c",a);
}
else
break;
}
else if(pre(st[i])>pre(s[top])||top==-1||s[top]=='(')
push(s,&top,st[i]);
else if(pre(st[i])<pre(s[top]))
{
for(int j=0;pre(s[top])>=pre(st[i]);j++)
{
m=pop(s,&top);
printf("%c",m);
}
push(s,&top,st[i]);
}


else
continue;
}
display(s,&top);
} 
