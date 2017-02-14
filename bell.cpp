#include<stdio.h>
#include<conio.h>
int dist[5];
int pred[5];
void Init_Shortest_Path(int s)
{
int i = 0;
for(i = 0; i < 5; ++i)
{
dist[i] = 9999;
pred[i] = -1;
}
dist[s] = 0;
}
void Relax(int u, int v, int w)
{
if(dist[v] > dist[u] + w)
{
dist[v] = dist[u] + w;
pred[v] = u;
}
}
int Bellman_Ford(int G[5][5], int s)
{
int i, j, k;
Init_Shortest_Path(s);
for(i = 0; i < 4; ++i) //For each vertex
{
for(j = 0; j < 5; ++j)
{
for(k = 0; k < 5; ++k)
{
if(G[j][k] != 0)
Relax(j, k, G[j][k]);
}
}
}
for(i = 0; i < 5; ++i)
{
for(j = 0; j < 5; ++j)
{
if(dist[j] > dist[i] + G[j][i])
return 0;
}
}
return 1;
}
void Path_trace(int s, int d)
{
int i = 0;
int j = d-1;
printf("\n\nPath trace from source(vertex %d) to dest(vertex %d):\n\n", s, d);
while(j != 0)
{
printf("%d -> ", j);
j = pred[j];
}
printf("%d", j);
}
void Print_Shortest_Path(int s)
{
int i = 0;
printf("\nShortest path from vertex %d (source):\n\n", s);
for(i = 0; i < 5; ++i)
printf("To vertex %d: %d\n",i, dist[i]);
}
int main()
{
int G[5][5] = { {0,6,7,0,0},
{0,0,8,5,-4},
{0,0,0,-3,9},
{0,-2,0,0,0},
{2,0,0,7,0}};
int retCode;
retCode = Bellman_Ford(G,0);
Print_Shortest_Path(0);
Path_trace(0,5);
getch();
return 0;
}