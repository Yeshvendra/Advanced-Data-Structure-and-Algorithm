#include<stdio.h>#include<stdio.h>
#include<string.h>
char n,l,t[50],p[20];
void mfa()
{
	int a[20]={0},b[20]={0},c[20]={0},q=0,pi[20]={0},i,j,k,x,flag=0,state;
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
	if(p[0]=='a')
		a[0]=1;
	else if(p[0]=='b')
		b[0]=1;
	else if(p[0]=='c')
		c[0]=1;
	q=1;
	for(i=1;i<l;i++)
	{
		if(p[i]=='a')
		{
			a[i]=++q;
			b[i]=b[pi[i]];
			c[i]=c[pi[i]];
		}
		else if(p[i]=='b')
		{
			b[i]=++q;
			a[i]=a[pi[i]];
			c[i]=c[pi[i]];
		}
		else if(p[i]=='c')
		{
			c[i]=++q;
			a[i]=a[pi[i]];
			b[i]=b[pi[i]];
		}	
	}
	a[i]=a[pi[i]];
	b[i]=b[pi[i]];
	c[i]=c[pi[i]];
	for(i=0;i<=l;i++)
		printf("\na[%d]=%d  b[%d]=%d  c[%d]=%d",i,a[i],i,b[i],i,c[i]);
	state=0;
	for(i=0;i<n;i++)
	{
		if(t[i]=='a')
			state=a[state];
		else if(t[i]=='b')
			state=b[state];
		else if(t[i]=='c')
			state=c[state];
		if(state==l)
			printf("\nHit at split %d.",i-l+1);
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
	mfa();
}	
