#include<stdio.h>
#include<conio.h>
int grade(int m)
{
if(m>=90 && m<=100)
return 10;
else if(m>=75 && m<90)
return 9;
else if(m>=60 && m<75)
return 8;
else if(m>=40 && m<60)
return 7;
else
return 0;
}
void main()
{
printf("Enter marks of 5 subjects \n");
int m1,m2,m3,m4,m5;
scanf("%d%d%d%d%d",&m1,&m2,&m3,&m4,&m5);
int sgpa=(5*grade(m1)+4*grade(m2)+5*grade(m3)+3*grade(m4)+3*grade(m5))/20;
printf("\n SGPA is %d",sgpa);
getch();
}
