#include<stdio.h>
void th(int n,char s,char t,char d)
{
    if(n==1)
    {
    printf("Move %d disc from %c to %c\n",n,s,d);
    return;
    }
    th(n-1,s,d,t);
    printf("Move %d disc from %c to %c\n",n,s,d);
    th(n-1,t,s,d);
}
void main()
{
  int n;
  char sc,te,de;
  printf("Enter no. of discs \n");
  scanf("%d",&n);
  printf("Enter name of towers \n");
  scanf("%c %c %c",&sc,&te,&de);
  th(n,sc,te,de);
}

