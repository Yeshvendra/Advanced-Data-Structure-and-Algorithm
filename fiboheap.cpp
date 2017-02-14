#include<stdio.h>
#include<iostream>
#include<stdlib.h>
using namespace std;
struct node{
	int key,mark,degree;
	node *p,*child,*left,*right;
};
struct head{
	int n;
	node *min;
};
head* MAKE_FIB_HEAP(){
	head *h;
	h=new head;
	h->n=0;
	h->min=NULL;
	return h;
}
void FIB_HEAP_INSERT(head *h,node *x){
	x->degree=0;
	x->p=NULL;
	x->child=NULL;
	x->left=x;
	x->right=x;
	x->mark=0;
	//head *h1;
	//h1=MAKE-FIB-HEAP();
	//FIBO-HEAP-UNION(h,h1);
	if(h->min==NULL)
		h->min=x;
	else{
		node* y;
		y=h->min->right;
		h->min->right=x;
		x->right=y;
		y->left=x;
		x->left=h->min;
		if(h->min==NULL||x->key<h->min->key)
			h->min=x;
	}
	h->n=h->n+1;
}
head* FIBO_HEAP_UNION(head *h1,head *h2){
	head* h;
	h=MAKE_FIB_HEAP();
	h->min=h1->min;
	//FIBO-HEAP-UNION(h1,h2);
	node *y,*z;
	y=h1->min->right;
	z=h2->min->right;
	h2->min->right=h1->min;
	h1->min->right=h2->min;
	y->left=z;
	z->left=y;
	if((h1->min==NULL)||(h2->min!=NULL&&h2->min->key<h1->min->key))
		h->min=h2->min;
	h->n=h1->n+h2->n;
	return h;
}
void FIB_HEAP_LINK(head *h,node *y,node *x){
	cout<<"\nfib-heap-link\n"<<y->key<<"  "<<x->key;
	(y->left)->right=y->right;
	(y->right)->left=y->left;
	//cout<<"1";
	if(x->right==x)
		h->min=x;
	y->left=y;
	y->right=y;
	y->p=x;
	if(x->child==NULL)
		x->child=y;
	y->right=x->child;
	y->left=x->child->left;
	x->child->left->right=y;
	x->child->left=y;
	if(y->key<x->child->key)
		x->child=y;
	/*if(x->child!=NULL){
		node *t;
		y->p=x;
		t=x->child->left;
		x->child->left=y;
		y->left=t;
		y->right=x->child;
		t->right=y;
	}*/
	x->degree+=1;
	y->mark=0;
}
void CONSOLIDATE(head *h){
	cout<<"\nconsolidate\n";
	node *A[100];
	int maxd=0;
	node *z;
	z=h->min;
	do{
		if(z->degree>maxd)
			maxd=z->degree;
		z=z->right;
	}while(z!=h->min);
	for(int i=0;i<=maxd;i++)
		A[i]=NULL;
	node *w;
	w=h->min;
	do{
		node *x;
		x=w;
		int d=x->degree;
		while(A[d]!=NULL){
			node *y;
			y=A[d];
			if(x->key>y->key){
				node *t;
				t=x;
				x=y;
				y=t;
			}
			FIB_HEAP_LINK(h,y,x);
			A[d]=NULL;
			d=d+1;
		}
		A[d]=x;
		w=w->right;
	}while(w!=h->min);
	h->min=NULL;
	for(int i=0;i<=maxd;i++){
		if(A[i]!=NULL){
			node *t;
			t=h->min->right;
			h->min->right=A[i];
			A[i]->right=t;
			t->left=A[i];
			A[i]->left=h->min;
			if(h->min==NULL||A[i]->key<h->min->key)
				h->min=A[i];
		}
	}
}
node* FIB_HEAP_EXTRACT_MIN(head *h){
	cout<<"\nfib-heap-extract-min\n";
	node *z;
	z=h->min;
	if(z!=NULL){
		node *x;
		x=z->child;
		node *t;
		t=z->child;
		if(x!=NULL)
			do{
				node* y;
				y=h->min->right;
				h->min->right=z;
				x->right=y;
				y->left=x;
				x->right=h->min;
				x->p=NULL;
				x=x->right;
				//cout<<"1";
			}while(x!=t);
		if(z==z->right){
			h->min=NULL;
		}
		else{
			//cout<<"2";
			h->min=z->right;
			CONSOLIDATE(h);
		}
		h->n=h->n-1;
	}
	return z;
}
void DISPLAY(head *h){
	node *x;
	x=h->min;
	if(x==NULL)
		cout<<"\nFibonacci heap is empty.";
	else{
		cout<<"\nRoots are :-\n";
		do{
			cout<<"-->"<<x->key;
			x=x->right;
		}while(x!=h->min);
	}
}
void FIB_HEAP_FIND_MIN(head *h){
	cout<<"\nMinimum : "<<h->min->key;
}
int main(){
	int cho;
	head *h;
	h=new head;
	h->min=NULL;
	h->n=0;
	do{
		cout<<"\n\nMENU :-\n";
		cout<<"\n1.Insert\n2.Find minimum element\n3.Extract minimum element\n4.Display\n5.Exit\nEnter your choice : ";
		cin>>cho;
		if(cho==1){
			int x;
			cout<<"\nEnter the number to be inserted : ";
			cin>>x;
			node *pt;
			pt=new node;
			pt->key=x;
			FIB_HEAP_INSERT(h,pt);
		}
		else if(cho==2){
			FIB_HEAP_FIND_MIN(h);
		}
		else if(cho==3){
			FIB_HEAP_EXTRACT_MIN(h);
		}
		else if(cho==4){
			DISPLAY(h);
		}
	}while(cho<5);
}
