#include<stdio.h>
int g[20][20],pred[20][20],n;
int main()
{
	int i,j,k,temp;
	printf("\nEnter the number of vertex : ");
	scanf("%d",&n);
	printf("\nEnter adjacency matrix :-\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&g[i][j]);
		}
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		if(g[i][j]!=0||g[i][j]!=9999)
			pred[i][j]=i+1;
		else
			pred[i][j]=-1;
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			for(k=0;k<n;k++)
			{
				g[j][k]=g[j][k]||(g[j][i]&&g[i][k]);
				/*if(g[j][k]>g[j][i]+g[i][k])
				{
					g[j][k]=g[j][i]+g[i][k];
					pred[j][k]=pred[i][k];
				}*/
			}
		}
	}
	printf("\nDistance Matrix :-\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%d  ",g[i][j]);
		}
		printf("\n");
	}
	/*printf("\nPred Matrix :-\n");
	for(i=0;i<n;i++)
		pred[i][i]=0;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%d  ",pred[i][j]);
		}
		printf("\n");
	}*/
}
