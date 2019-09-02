#include<stdio.h>
void main()
{
	int p[100];
	int t[100];
	int s=0;
	int ch,ch1=-6;
	int x=0;
	do
	{
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				scanf("%d",&p[x]);
				scanf("%d",&t[x]);
				x++;
				break;
				case 2:
					for(int j=0;j<x;j++)
	{
		s+=t[j];
		printf("Process %d takes %d seconds to complete \n",p[j],s);
}
break;
					
		}
		scanf("%d",&ch1);
		
	}while(ch1!=0);

}
