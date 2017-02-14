#include<stdio.h>
int d[20],f[20],g[20][20],gt[20][20],n,pred[20],color[20],time,top[20],top1[20],count=0;
#define white 1
#define gray 2
#define black 3
void dfs_visit(int);
void dfs_visit1(int);
int main()
{
	int i,j,u;
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
	for(i=1;i<=n;i++)
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
	//printf("\n\n\nTopological Sort :- \n");
	for(i=count;i>=1;i--)
	{
		printf("\n%d - > %d",7-i,top[i]);
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			gt[j][i]=g[i][j];
		}
	}
	printf("\nTranspose of Adjacency Matrix:-\n");
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			printf("%d  ",gt[i][j]);
		}
		printf("\n");
	}
	for(i=1;i<=n;i++)
	{
		color[i]=white;
		pred[i]=NULL;
	}
	time=0;
	for(u=1;u<=n;u++)
		if(color[top[u]]==white)
		{
			dfs_visit1(top[u]);
			printf("\n");
		}
	for(i=1;i<=n;i++)
	{
	printf("\nFor vertex %d Discovery time = %d and Finish time : %d",i,d[i],f[i]);
	}
	return 0;
}
void dfs_visit(int u)
{
	int v;
	time=time+1;
	d[u]=time;
	color[u]=gray;
	for(v=1;v<=n;v++)
	{
		if((g[u][v]==1)&&(color[v]==white))
		{
			pred[v]=u;
			dfs_visit(v);
		}
	}	
	color[u]=black;
	time=time+1;
	f[u]=time;
	top[++count]=u;
}
void dfs_visit1(int u)
{
	int v;
	time=time+1;
	d[u]=time;
	color[u]=gray;
	for(v=1;v<=n;v++)
	{
		if((gt[u][v]==1)&&(color[v]==white))
		{
			pred[v]=u;
			dfs_visit(v);
			printf("\nvertex %d ",v);
		}
	}	
	color[u]=black;
	time=time+1;
	f[u]=time;
	top1[++count]=u;
	printf("\nvertex %d ",u);
}
	
	
	
	
	


