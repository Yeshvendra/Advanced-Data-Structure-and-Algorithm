#include<stdio.h>
#include<iostream>
#include<stdlib.h>
using namespace std;
struct node{
	int n,degree;
	node *parent,*child,*sibling;
};
node *head;
node* Make_Binomial_Heap(){
	node *h;
	h=new node;
	//headh=NULL;
	return h;
}
node* Merge_Binomial_Heap(node* h1,node* h2){
	node *h;
	h=Make_Binomial_Heap();
	node *y,*z,*a,*b;
	y=h1;
	z=h2;
	if(y!=NULL){
		if(z!=NULL){
			if(y->degree<=z->degree){
				h=y;
			}
			else if(y->degree>z->degree)
				h=z;
		}
		else
			h=y;
	}
	else
		h=z;
	while(y!=NULL&&z!=NULL){
		if(y->degree<z->degree)
			y=y->sibling;
		else if(y->degree==z->degree){
			a=y->sibling;
			y->sibling=z;
			y=a;
		}
		else{
			b=z->sibling;
			z->sibling=y;
			z=b;
		}
	}
	return h;
}
void Binomial_Link(node *y,node *z){
	y->parent=z;
	y->sibling=z->child;
	z->child=y;
	z->degree=z->degree+1;
}
node *Binomial_Heap_Union(node *h1,node *h2){
	node *h,*x,*next_x,*prev_x;
	h=Make_Binomial_Heap();
	head=Merge_Binomial_Heap(h1,h2);
	if(h==NULL)
		return h;
	prev_x=NULL;
	x=head;
	next_x=x->sibling;
	while(next_x!=NULL){
		if((x->degree!=next_x->degree)||(next_x->sibling!=NULL&&next_x->sibling->degree==x->degree)){
			prev_x=x;
			x=next_x;
		}
		else if(x->n<=next_x->n){
			x->sibling=next_x->sibling;
			Binomial_Link(next_x,x);
		}
		else if(prev_x==NULL)
			h=next_x;
		else{
			prev_x->sibling=next_x;
			Binomial_Link(x,next_x);
		}
		x=next_x;
		next_x=x->sibling;
	}
	return h;
} 
void Binomial_Heap_Insert(node *h,node *x){
	node *h1;
	h1=Make_Binomial_Heap();
	x->parent=NULL;
	x->child=NULL;
	x->sibling=NULL;
	x->degree=0;
	h1=x;
	h=Binomial_Heap_Union(h,h1);
}
node *Binomial_Heap_Min(node *h){
	int min;
	node *y,*x;
	y=NULL;
	x=h;
	min=999999;
	while(x!=NULL){
		if(x->n<min){
			min=x->n;
			y=x;
		}
		x=x->sibling;
	}
	return y;
}
int Display(node *h){
	if(h==NULL){
		cout<<"\nThe Heap is Empty.";
		return 0;
	}
	cout<<"\nThe Binomial Heap is :-";
	node *p,*q,*r;
	p=h;
	while(p!=NULL){
		cout<<"\nroot : "<<p->n<<"\n";
		q=p->child;
		while(q!=NULL){
			r=q;
			while(r!=NULL){
				cout<<r->n<<" ";
				r=r->sibling;
			}
			cout<<"\n";
			q=q->child;
		}
		/*if(p->sibling!=NULL)
			cout<<"-->";*/
		p=p->sibling;
	}
	cout<<"\n";
	return 0;
}
int main(){
	int i,x,ch;
	do{
		cout<<"1.Insert\n2.Find Minimum\n3.Display the Binomial Heap\n4.Exit\nEnter your choice : ";
		cin>>ch;
		if(ch==1){
				cout<<"\nEnter the element to be entered : ";
				cin>>x;
				node *p=new node;
				p->n=x;
				Binomial_Heap_Insert(head,p);
		}
		else if(ch==2){
				cout<<"\nMinimum in the Binomial Tree : "<<Binomial_Heap_Min(head)->n<<"\n";
		}
		else if(ch==3){
				Display(head);
		}
		else if(ch==4){
				cout<<"\nThank You !!";
		}
		else{
				cout<<"\nWrong Choice !!";
		}
	}while(ch!=4);
}
