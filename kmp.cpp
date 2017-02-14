#include<stdio.h>
#include<string.h>
char n,l,t[50],p[20];
void kmp()
{
	int q=0,pi[20]={0},i,j,k,x,flag=0;
	char temp[20],temp1[20];
	pi[0]=0;
	for(i=1;i<=l;i++)
	{
		temp[20]={'\0'},temp1[20]={'\0'};
		for(j=0;j<i;j++)
		{
			temp[j]=p[j];
		}
		temp[j]='\0';
		//printf("\nt %s",temp);
		for(j=1;j<i;j++)
		{
			for(k=j;temp[k]!='\0';k++)
				temp1[k-j]=temp[k];
			temp1[k-j]='\0';
			//printf("\nt1 %s",temp1);
			flag=0;
			for(x=0;x<strlen(temp1);x++)
			{
				if(temp1[x]==p[x])
				{
					//printf("\nmatch");
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
				pi[i]=strlen(temp1);
				break;
			}
		}
	}
	for(i=1;i<=l;i++)
		printf("\npi[%d]:%d",i,pi[i]);
	printf("\n");
	for(i=0;i<n;i++)
	{
		while(q>0&&p[q]!=t[i])
		{
			q=pi[q];
		}
		if(p[q]==t[i])
		{
			//printf("IN");	
			q=q+1;
		}
		//printf("%d  ",q);
		if(q==l-1)
		{
			printf("\nHit occured with %d splits.",i-l+2);
			q=pi[q];
		}
	}
}
int main()
{
	printf("\nEnter the text : ");
	gets(t);
	n=strlen(t);
	printf("\nEnter the pattern : ");
	gets(p);
	l=strlen(p);
	kmp();
}
