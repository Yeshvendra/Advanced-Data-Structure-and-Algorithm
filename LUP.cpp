#include<stdio.h>
#include<math.h>
int n,p[1][10];
float a[10][10],l[10][10]={0},u[10][10]={0};
int main(){
	int i,j,k,large,lj;
	float t;
	printf("\nEnter the number of equations : ");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		p[0][i]=i+1;
	}
	printf("\nP matrix is :-\n");
	for(j=0;j<n;j++)
	{
		printf("%d\n",p[0][j]);
	}
	printf("\nEnter the matrix:-\n");
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			scanf("%g",&a[i][j]);
		}
	}
	for(i=0;i<n;i++){
		large=a[i][i];
		for(j=i;j<n;j++){
			if(large<abs(a[j][i])){
				lj=j;
				large=abs(a[j][i]);
			}
		}
		//printf("\np : %d",lj);
		t=p[0][i];
		p[0][i]=p[0][lj];
		p[0][lj]=t;
		for(k=0;k<n;k++){
			t=a[lj][k];
			a[lj][k]=a[i][k];
			a[i][k]=t;
		}
		for(j=i+1;j<n;j++)
		{
			a[j][i]=a[j][i]/a[i][i];
		}
		for(j=i+1;j<n;j++){
			for(k=i+1;k<n;k++){
				a[j][k]=a[j][k]-(a[i][k]*a[j][i]);
			}
		}
	}
	printf("\nAfter LUP decomposition matrix is :-\n");
	for(i=0;i<n;i++){
		for(j=0;j<n;j++)
		{
			printf("%0.1f  ",a[i][j]);
		}
		printf("\n");
	}
	for(i=0;i<n;i++)
		l[i][i]=1;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++){
			if(i>j)
				l[i][j]=a[i][j];
			else
				u[i][j]=a[i][j];
		}
	}
	printf("\nL matrix is :-\n");
	for(i=0;i<n;i++){
		for(j=0;j<n;j++)
		{
			printf("%0.1f  ",l[i][j]);
		}
		printf("\n");
	}
	printf("\nU matrix is :-\n");
	for(i=0;i<n;i++){
		for(j=0;j<n;j++)
		{
			printf("%0.1f  ",u[i][j]);
		}
		printf("\n");
	}
	printf("\nP matrix is :-\n");
	for(j=0;j<n;j++)
	{
		printf("%d\n",p[0][j]);
	}
	return 0;
}
