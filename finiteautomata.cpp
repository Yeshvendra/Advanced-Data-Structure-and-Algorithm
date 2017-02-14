#include<stdio.h>
#include<string.h>
char n,l,t[50],p[20];
void FA()
{
	int state,pos,i,j,k,x,flag=0;
	char temp[20],temp1[20];
	int a[21]={0},b[21]={0},c[21]={0};
	for(i=0;i<=l;i++)
	{
		temp[20]={'\0'},temp1[20]={'\0'};
		//printf("1");
		for(j=0;j<i;j++)
		{
			temp[j]=p[j];
		}
		temp[j]='a';
		temp[j+1]='\0';
		for(k=strlen(temp)-1;k>=0;k--)//1 - 0
		{
			//printf("\nt%s",temp);
			for(x=k;temp[x]!='\0';x++)
				temp1[x-k]=temp[x];
			temp1[x-k]='\0';
			pos=0;
			flag=0;
			for(x=0;x<strlen(temp1);x++)
			{
				//printf("\nt1%s",temp1);
				if(temp1[x]==p[x])
				{
					//printf("\nmatch");
					pos=x;
					flag=1;
				}
				else
				{
					pos=-1;
					flag=0;
					break;
				}
			}
			if(flag==1)
			{	
				a[i]=pos+1;
				//printf("pos:%d",a[i]);
			}
			/*if(flag==0)
			{
				a[i]=0;
				//printf("pos:%d",a[i]);
			}*/
		}
		temp[j]='b';
		temp[j+1]='\0';
		for(k=strlen(temp)-1;k>=0;k--)
		{
			//printf("\n");
			for(x=k;temp[x]!='\0';x++)
				temp1[x-k]=temp[x];
			temp1[x-k]='\0';
			pos=0;
			flag=0;
			for(x=0;x<strlen(temp1);x++)
			{
				if(temp1[x]==p[x])
				{
					pos=x;
					flag=1;
				}
				else
				{
					flag=0;
					break;
				}
			}
			if(flag==1)
				b[i]=pos+1;
			/*if(flag==0)
				b[i]=0;*/	
		}
		temp[j]='c';
		temp[j+1]='\0';
		for(k=strlen(temp)-1;k>=0;k--)
		{
			for(x=k;temp[x]!='\0';x++)
				temp1[x-k]=temp[x];
			temp1[x-k]='\0';
			pos=0;
			flag=0;
			for(x=0;x<strlen(temp1);x++)
			{
				if(temp1[x]==p[x])
				{
					pos=x;
					flag=1;
				}
				else
				{
					flag=0;
					break;
				}
			}
			if(flag==1)
				c[i]=pos+1;
			/*if(flag==0)
				c[i]=0;*/	
		}
		printf("\na[%d]=%d  b[%d]=%d  c[%d]=%d",i,a[i],i,b[i],i,c[i]);
	}
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
	FA();
}
