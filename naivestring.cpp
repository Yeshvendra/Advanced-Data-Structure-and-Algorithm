#include<stdio.h>
#include<string.h>
int main()
{
	int s,i,j,k,flag=0,np,nt;
	char p[20],t[100];
	printf("\nEnter a text : ");
	gets(t);
	printf("\nEnter a pattern : ");
	gets(p);
	np=strlen(p);
	nt=strlen(t);
	for(i=0;i<nt-np+1;i++)
	{
		for(j=0;j<np;j++)
		{
			if(t[i+j]==p[j])
			{
				flag=1;
			}
			else
			{
				flag=0;
				break;
			}
		}
		if(flag==1)
		{
			printf("\nPattern matched at shift %d.",i);
		}
	}
	return 0;
}
