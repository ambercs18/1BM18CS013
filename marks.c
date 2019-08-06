#include<stdio.h>
#include<conio.h>
void main()
{
structure student
{
int m1,m2,m3,m4,m5;
};
struct student x;
printf("Enter the marks of 5 subjects \n");
scanf("%d%d%d%d%d",&x.m1,&x.m2,&x.m3,&x.m4,&x.m5);
printf("\n The marks of students are");
printf("The marks in subject 1 is %d \n",x.m1);
printf("The marks in subject 2 is %d \n",x.m2);
printf("The marks in subject 3 is %d \n",x.m3);
printf("The marks in subject 4 is %d \n",x.m4);
printf("The marks in subject 5 is %d \n",x.m5);
getch();
}
