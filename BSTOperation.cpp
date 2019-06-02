#include<bits/stdc++.h>
#define ll long long 
#define INF 0x3f3f3f3f
using namespace std;
//const int N=100;
vector<pair<ll,ll>>g;
ll n,m;
/*
5
i 1
i 2
i 0
d 2
i 3*/
struct node
{
    int data,pos;
    struct node* left,*right;
};

struct node *newNode(int n, int p)
{
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->data=n;
    temp->pos=p;
    temp->left=temp->right=NULL;
    return temp;
}
struct node* insert(struct node* element,int key, int p)
{
    if(element==NULL)
    {
        element=newNode(key,p);
        cout<<element->pos<<endl;
        return element;
    }
    if(key<(element->data))
    {
        element->left=insert(element->left,key,2*p);
    }
    else
    {
        element->right=insert(element->right,key,2*p+1);
    }
    return element;
}
struct node* deleteNode(struct node* element,int key)
{
    if(element==NULL)
    {
        return element;
    }
    if(key<(element->data))
    {
        element->left=deleteNode(element->left,key);
    }
    else if(key>(element->data))
    {
        element->right=deleteNode(element->right,key);
    }
    else
    {
        cout<<element->pos<<endl;
        if(element->left==NULL)
        {
            struct node* temp=element->right;
            free(element    );
            return temp;
        }
        else if(element->right==NULL)
        {
            struct node* temp=element->left;
            free(element);
            return temp;
        }
        struct node* current=element->right;
        while(current->left!=NULL)
        {
            current=current->left;
        }
        element->data=current->data;
        element->right=deleteNode(element->right,current->data);
    }
    return element;
}
int main()
{
    ll t,i,j,n;
    cin>>t;
    struct node *root=NULL;
    while(t--)
    {
        char c;
        cin>>c>>n;
        if(c=='i')
        {
            insert(root,n,1);
        }
        else
        {
            deleteNode(root,n);
        }
    }
}