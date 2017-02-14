#include<stdio.h>
#include<conio.h>
#define MAX 5
#define INF 998
int allselected(int *selected)
{
int i;
for(i=0;i<MAX;i++)
if(selected[i]==0)
return 0;
return 1;
}
void shortpath(int cost[][MAX],int *preced,int *distance)
{
int selected[MAX]={0};
int current=0,i,k,dc,smalldist,newdist;
for(i=0;i<MAX;i++)
distance[i]=INF;
selected[current]=1;
distance[0]=0;
current=0;
while(!allselected(selected))
{
smalldist=INF;
dc=distance[current];
for(i=0;i<MAX;i++)
{
if(selected[i]==0)
{
newdist=dc+cost[current][i];
if(newdist<distance[i])
{
distance[i]=newdist;
preced[i]=current;
}
if(distance[i]<smalldist)
{
smalldist=distance[i];
k=i;
}
}
}
current=k;
selected[current]=1;
}
}
void main()
{
int cost[MAX][MAX]=
{{0,10,INF,5,INF},
{INF,0,1,2,INF},
{INF,INF,0,INF,4},
{INF,3,9,0,2},
{7,INF,6,INF,0}};
int i,preced[MAX]={0},distance[MAX];
shortpath(cost,preced,distance);
for(i=0;i<MAX;i++)
{
printf("Shortest Distance From source to node %d = %d \n",i,distance[i]);
}
getch();
}