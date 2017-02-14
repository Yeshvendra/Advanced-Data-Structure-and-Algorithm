#include<stdio.h>
#include<stdlib.h>
int g[20][20],n,dist[20],pred[20],visit[20]={0};
/*#define white 1
#define gray 2
#define black 3
void dfs_visit(int);*/
int relax(int u,int v,int w)
{
	if(dist[v]>dist[u]+w)
	{
		dist[v]=dist[u]+w;
		pred[v]=u;
		return 0;
	}
	return 1;
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
	/*for(i=1;i<=n;i++)
	{
		color[i]=white;
		pred[i]=NULL;
	}
	time=0;
	for(u=1;u<=n;u++)
		if(color[u]==white)
			dfs_visit(u);
	for(i=1;i<=n;i++)
	{
	printf("\nFor vertex %d Discovery time = %d and Finish time : %d",i,d[i],f[i]);
	}
	printf("\n\n\nTopological Sort :- \n");
	for(i=count;i>=1;i--)
	{
		printf("\n%d - > %d",7-i,top[i]);
		if(g[top[i+1]][top[i]]==0)
			printf("\nAnother tree :");
	}*/
	printf("\nEnter the starting vertex : ");
	scanf("%d",&s);
	init_SS(s);
	for(i=1;i<=n;i++)
	{
		/*min=99999;
		for(j=1;j<=n;j++)
		{
			if(min>dist[j]&&visit[j]==0&&j!=i)
			{
				min=dist[j];
				temp=j;
			}		
		}
		visit[temp]=1;*/
		for(j=1;j<=n;j++)
		{
			if(g[i][j]!=0&&g[i][j]!=9999)
				relax(i,j,g[i][j]);
		}
	}
	for(i=0;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(g[i][j]!=0&&g[i][j]!=9999)
			{
				if(relax(i,j,g[i][j]))
				{
					printf("\nThe Graph is cyclic !!");
					exit(0);
				}
			}
		}
	}
	printf("\n");
	for(j=1;j<=n;j++)
	{
		printf("\nFor vertex %d distance to %d is : %d and pred is : %d.",s,j,dist[j],pred[j]);
	}
	return 0;
}

