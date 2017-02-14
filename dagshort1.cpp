#include<stdio.h>
int d[20],f[20],g[20][20],n,dist[20],pred[20],color[20],time,top[20],count=0;
#define white 1
#define gray 2
#define black 3
void dfs_visit(int);
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
	int i,j,u,k,s;
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
	init_SS(top[count]);
	for(i=count;i>=1;i--)
	{
		for(j=1;j<=n;j++)
		{
			if(g[top[i]][j]!=0&&g[top[i]][j]!=9999)
				relax(top[i],j,g[top[i]][j]);
		}
	}
	for(j=1;j<=n;j++)
	{
		printf("\nFor vertex %d distance to %d is : %d and pred is : %d",top[count],j,dist[j],pred[j]);
		k=pred[j];
		while(pred[k]!=0&&pred[k]!=-1)
		{
			printf(" pred is : %d",pred[k]);
			k=pred[k];
		}
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
		if(((g[u][v]!=0)||(g[u][v]!=9999))&&(color[v]==white))
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

	
	
	
	
	


