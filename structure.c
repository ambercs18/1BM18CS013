#include<stdio.h>
struct student
{
int id,age,marks;
};
struct student s;
void main()
{
printf("Enter the details \n);
scanf("%d%d%d",&s.id,&s.age,&s.marks);
if(s.age>20 && s.marks>=0 && s.marks<=100)
{
if(s.marks>=65)
{
printf("Admission Granted");
}
else
{
printf("Admission Not Granted");
}
}
else
printf("Data Invalid");
}

