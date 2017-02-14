# include <stdio.h>
# include <conio.h>
# include <stdlib.h>
# define sz 20
# define INF 200000
void print(unsigned long s[][sz], int i, int j)
{
if (i == j)
printf(" A%d ",i);
else
{
printf(" ( ");
print(s, i, s[i][j]);
print(s, s[i][j] + 1, j);
printf(" ) ");
}
}
void printm(unsigned long m[][sz], int n)
{
int i,j;
for(i=1;i<=n;i++)
{
for(j=1;j<=n;j++)
{
printf("%7d",m[i][j]);
}
printf("\n\n");
}
printf("\nThe No. of multiplication required is : %d",m[1][n]);
}
void Matrix_Chain_Order(int p[],int num)
{
unsigned long m[sz][sz] = {0};
unsigned long s[sz][sz] = {0};
unsigned int q = 0;
int i, j, k, l;
int n = num;
for(i = 1; i <= n; i++)
m[i][i] = 0;
for(l = 2; l <= n; l++)
for(i = 1; i <= (n - l + 1); i++)
{
j = i + l - 1;
m[i][j] = INF;
for(k = i; k <= j - 1; k++)
{
q = m[i][k] + m[k+1][j] + p[i-1] * p[k] * p[j];
if(q < m[i][j])
{
m[i][j] = q;
s[i][j] = k;
}
}
}
print(s, i-1, j);
printf("\n\n");
printf("The Minimum No. of Multiplication Required is:\n\n");
printm(m,n);
}
main()
{
int i,num=0,p[sz]={0};
printf("Enter the number of matrix : ");
scanf("%d",&num);
printf("Enter order sequence of matrix :-\n");
for(i=0;i<=num;i++)
scanf("%d",&p[i]);
printf("\nMultiplication Sequence is :-\n ");
Matrix_Chain_Order(p,num);
return 0;
}
