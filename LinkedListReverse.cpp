#include <bits/stdc++.h>
using namespace std;
struct node 
{
    int data;
    struct node *next;
};
void getRev(struct node *head)
{
    if(head==NULL)
    {
        return;
    }
    getRev(head->next);
    printf("%d ",head->data);
}
/*void print(struct node *head)
{
    if(head==NULL)
    {
        return;
    }
    printf("%d ",head->data);
    print(head->next);
}*/
void getStck(struct node *head)
{
    stack<node *>st;
    struct node *ptr=head;
    while(ptr!=NULL)
    {
        st.push(ptr);
        ptr=ptr->next;
    }
    while(!st.empty())
    {
        struct node *p=st.top();
        cout<<p->data<<" ";
        st.pop();
    }
}
int getNode(struct node *head,int p)
{
    struct node *ptr=head;
    int i=1;
    while(i<p)
    {
        ptr=ptr->next;
        i++;
    }
    return ptr->data;
}
void getSimpleLoop(struct node *head)
{
    struct node *ptr=head;
    int cnt=0;
    while(ptr!=NULL)
    {
        cnt++;
        ptr=ptr->next;
    }
    for(int i=cnt;i>0;i--)
    {
        int p=getNode(head,i);
        cout<<p<<" ";
    }
}
int main()
{
    int n,m;
    //cout<<"Enter the number of elements :"<<endl;
    scanf("%d",&n);
    //cout<<"Enter the elements:"<<endl;
    struct node *head = NULL;
    struct node *p,*q;
    p = (struct node*)malloc(sizeof(struct node));
    scanf("%d",&m);
    p->data = m;
    p->next = NULL;
    head = p; 
    for(int i=1;i<n;i++)
    {
        scanf("%d",&m);
        q=(struct node*)malloc(sizeof(struct node));
        q->data=m;
        q->next=NULL;
        p->next=q;
        p=p->next;
        //push(&head,m);
    }
    //print(head);
    getRev(head); //using recursion
    cout<<endl;
    getStck(head);   //stack
    cout<<endl;
    getSimpleLoop(head); // using loop 
}