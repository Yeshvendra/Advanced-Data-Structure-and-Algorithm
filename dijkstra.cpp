#include<stdio.h>
int g[20][20],n,dist[20],pred[20],visit[20]={0};
void relax(int u,int v,int w)
{
	if(dist[v]>dist[u]+w)
	{
		dist[v]=dist[u]+w;
		pred[v]=u;
	}
}
void init_SS(int s)
{
	int i;
	for(i=1;i<=n;i++)
	{
		dist[i]=9999;
		pred[i]=-1;
	}
	dist[s]=0;
}
int main()
{
	int i,j,u,s,min,temp;
	printf("Enter the number of vertex : ");
	scanf("%d",&n);
	printf("Enter the adjacency matrix :-\n");
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			scanf("%d",&g[i][j]);
		}
	}
	printf("\nEnter the starting vertex : ");
	scanf("%d",&s);
	init_SS(s);
	for(i=1;i<=n;i++)
	{
		min=99999;
		for(j=1;j<=n;j++)
		{
			if(min>dist[j]&&visit[j]==0&&j!=i)
			{
				min=dist[j];
				temp=j;
			}		
		}
		visit[temp]=1;
		for(j=1;j<=n;j++)
		{
			if(g[temp][j]!=0&&g[temp][j]!=9999)
				relax(temp,j,g[temp][j]);
		}
	}
	printf("\n");
	for(j=1;j<=n;j++)
	{
		printf("\nFor vertex %d distance to %d is : %d and pred is : %d.",s,j,dist[j],pred[j]);
	}
	return 0;
}

	
	
	
	
	


