#include<stdio.h>
#include<math.h>
int temp=0,temp1=0,l,n,t[50],p[20],tm[50],pm;
void rabin_karp()
{
		int i,j,x,y=1,flag=0;
		pm=temp1%13;
		printf("\nmod of p : %d",pm);
		for(j=0;j<l-1;j++)
				y*=10;
		for(i=0;i<=n-l;i++)
		{
			tm[i]=temp%13;
			printf("\nmod of t at split %d of value %d: %d",i,temp,tm[i]);
			x=temp%y;
			x*=10;
			temp=x+t[l+i];
		}
		for(i=0;i<=n-l;i++)
		{
			if(tm[i]==pm)
			{
				flag=0;
				printf("\nHit occured !");
				for(j=0;j<l;j++)
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
					printf("\nValid hit at split: %d .",i);
				else
					printf("\nInvalid hit at split: %d .",i);
			}
		}
}
int main()
{
	int i;
	printf("\nEnter the size of text : ");
	scanf("%d",&n);
	printf("\nEnter the text : ");
	for(i=0;i<n;i++)
		scanf("%d",&t[i]);
	printf("\nEnter the size of pattern : ");
	scanf("%d",&l);
	printf("\nEnter the pattern : ");
	for(i=0;i<l;i++)
		scanf("%d",&p[i]);
	for(i=0;i<l;i++)
	{
		temp*=10;
		temp+=t[i];
	}
	for(i=0;i<l;i++)
	{
		temp1*=10;
		temp1+=p[i];
	}	
	//printf("\n%d",temp);
	rabin_karp();
}
