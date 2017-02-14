#include<stdio.h>
#include<math.h>
float a[50]={0.0},b[50]={0.0};
void bit_reversal(int n){
	float t;
	if(n=8){
		t=a[1];
		a[1]=a[4];
		a[4]=t;
		t=a[3];
		a[3]=a[6];
		a[6]=t;
	}
}
int main()
{
	int i,j,k,n;
	float m,wn,w,t,u;
	printf("\nEnter the number of input : ");
	scanf("%d",&n);
	printf("\nEnter the inputs:-\n");
	for(i=0;i<n;i++){
		scanf("%f",&a[i]);
	}
	bit_reversal(n);
	printf("\n");
	for(i=1;i<=log(n)/log(2);i++){
		m=pow(2,i);
		wn=exp(2*3.14/m);
		for(k=0;k<=(n-1)/m;k++){
			w=1;
			for(j=0;j<=m/2-1;j++){
				if(j%(2*i)==0){
				t=w*a[(int)(k+j+m/2)]+w*b[(int)(k+j+m/2)];
				u=a[(int)(k+j)]+b[(int)(k+j)];
				a[(int)(k+j)]=u+t;
				a[(int)(k+j+m/2)]=u-t;
				}
				else{
				t=w*a[(int)(k+j+m/2)]+w*b[(int)(k+j+m/2)];
				u=a[(int)(k+j)]+b[(int)(k+j)];
				b[(int)(k+j)]=u+t;
				b[(int)(k+j+m/2)]=u-t;
				w=w*wn;
				}
			}
		}
	}
	printf("Answer :- \n");
	for(i=0;i<n;i++){
		printf("%0.1f+i%0.1f\n",a[i],b[i]);
	}
}
