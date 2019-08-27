#include<stdio.h>
int f(int n)
{
if(n==0)
return 1;
else
return (n*f(n-1));
}
      void main()
    {
        int n;
        printf("Enter number \n");
        scanf("%d",&n);
        printf("%d",f(n));
}

