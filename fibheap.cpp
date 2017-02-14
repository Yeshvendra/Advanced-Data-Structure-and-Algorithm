/*
 * C++ Program to Implement Fibonacci Heap
 */
#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;
struct node
{
    int n;
    int degree;
    node* parent;
    node* child;
    node* left;
    node* right;
    char mark;
    char C;
};
class FibonacciHeap
{
    private:
        int nH;
        node *H;
    public:
        node* InitializeHeap();
        int Fibonnaci_link(node*, node*, node*);
        node *Create_node(int);
        node *Insert(node *, node *);
        node *Extract_Min(node *);
        int Consolidate(node *);
        int Display(node *);
        FibonacciHeap()
        {
            H = InitializeHeap();
        }
};
node* FibonacciHeap::InitializeHeap()
{
    node* np;
    np = NULL;
    return np;
}
node* FibonacciHeap::Create_node(int value)
{
    node* x = new node;
    x->n = value;
    return x;
}
node* FibonacciHeap::Insert(node* H, node* x)
{
    x->degree = 0;
    x->parent = NULL;
    x->child = NULL;
    x->left = x;
    x->right = x;
    x->mark = 'F';
    x->C = 'N';
    if (H != NULL)
    {
        (H->left)->right = x;
        x->right = H;
        x->left = H->left;
        H->left = x;
        if (x->n < H->n)
            H = x;
    }
    else
    {
        H = x;
    }
    nH = nH + 1;
    return H;
}
int FibonacciHeap::Fibonnaci_link(node* H1, node* y, node* z)
{
    (y->left)->right = y->right;
    (y->right)->left = y->left;
    if (z->right == z)
        H1 = z;
    y->left = y;
    y->right = y;
    y->parent = z;
    if (z->child == NULL)
        z->child = y;
    y->right = z->child;
    y->left = (z->child)->left;
    ((z->child)->left)->right = y;
    (z->child)->left = y;
    if (y->n < (z->child)->n)
        z->child = y;
    z->degree++;
}
int FibonacciHeap::Display(node* H)
{
    node* p = H;
    if (p == NULL)
    {
        cout<<"The Heap is Empty"<<endl;
        return 0;
    }
    cout<<"The root nodes of Heap are: "<<endl;
    do
    {
        cout<<p->n;
        p = p->right;
        if (p != H)
        {
            cout<<"-->";
        }
    }
    while(p!=H);
    cout<<endl;
}
node* FibonacciHeap::Extract_Min(node* H1)
{
    node* p;
    node* ptr;
    node* z = H1;
    p = z;
    ptr = z;
    if (z == NULL)
        return z;
    node* x;
    node* np;
    x = NULL;
    if (z->child != NULL)
        x = z->child;
    if (x != NULL)
    {
        ptr = x;
        do
        {
            np = x->right;
            (H1->left)->right = x;
            x->right = H1;
            x->left = H1->left;
            H1->left = x;
            if (x->n < H1->n)
                H1 = x;
            x->parent = NULL;
            x = np;
        }
        while (np != ptr);
    }
    (z->left)->right = z->right;
    (z->right)->left = z->left;
    H1 = z->right;
    if (z == z->right && z->child == NULL)
        H = NULL;
    else
    {
        H1 = z->right;
        Consolidate(H1);
    }
    nH = nH - 1;
    return p;
}
int FibonacciHeap::Consolidate(node* H1)
{
    int d, i;
    float f = (log(nH)) / (log(2));
    int D = f;
    node* A[D];
    for (i = 0; i <= D; i++)
        A[i] = NULL;
    node* x = H1;
    node* y;
    node* np;
    node* pt = x;
    do
    {
        pt = pt->right;
        d = x->degree;
        while (A[d] != NULL)
        {
            y = A[d];
            if (x->n > y->n)
            {
                np = x;
                x = y;
                y = np;
            }
            if (y == H1)
                H1 = x;
            Fibonnaci_link(H1, y, x);
            if (x->right == x)
                H1 = x;
                A[d] = NULL;
            d = d + 1;
        }
        A[d] = x;
        x = x->right;
    }
    while (x != H1);
    H = NULL;
    for (int j = 0; j <= D; j++)
    {
        if (A[j] != NULL)
        {
            A[j]->left = A[j];
            A[j]->right =A[j];
            if (H != NULL)
            {
                (H->left)->right = A[j];
                A[j]->right = H;
                A[j]->left = H->left;
                H->left = A[j];
                if (A[j]->n < H->n)
                H = A[j];
            }
            else
            {
                H = A[j];
            }
            if(H == NULL)
                H = A[j];
            else if (A[j]->n < H->n)
                H = A[j];
        }
    }
}
int main()
{
    int n, m, l;
    FibonacciHeap fh;
    node* p;
    node* H;
    H = fh.InitializeHeap();
    while (1)
    {
        cout<<"----------------------------"<<endl;
        cout<<"Operations on Fibonacci heap"<<endl;
        cout<<"----------------------------"<<endl;
        cout<<"1)Insert Element in the heap"<<endl;
        cout<<"2)Extract Minimum key node"<<endl;
        cout<<"3)Find Minimum key node"<<endl;
        cout<<"4)Display Heap"<<endl;
        cout<<"5)Exit"<<endl;
        cout<<"Enter Your Choice: ";
        cin>>l;
        switch(l)
        {
        case 1:
            cout<<"Enter the element to be inserted: ";
            cin>>m;
            p = fh.Create_node(m);
            H = fh.Insert(H, p);
            break;
        case 2:
            p = fh.Extract_Min(H);
            if (p != NULL)
                cout<<"The node with minimum key: "<<p->n<<endl;
            else
                cout<<"Heap is empty"<<endl;
            break;
        case 3:
            cout<<"Minimum key node : "<<H->n<<endl;
            break;
        case 4:
            cout<<"The Heap is: "<<endl;
            fh.Display(H);
            break;
        case 5:
            exit(1);
        default:
            cout<<"Wrong Choice"<<endl;
        }
    }
    return 0;
}
