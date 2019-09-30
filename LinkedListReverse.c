//gcc 5.4.0

#include  <stdio.h>
#include <stdlib.h>
struct node 
{
    int data;
    struct node *next;
};
void getRev(struct node* head)
{
    if(head==NULL)
    {
        return;
    }
    getRev(head->next);
    printf("%d ",head->data);
}
void print(struct node* head)
{
    if(head==NULL)
    {
        return;
    }
    printf("%d ",head->data);
    print(head->next);
}
void push(struct node** head_ref, int new_data) 
{ 
    struct node* new_node = (struct node*)malloc(sizeof(struct node)); 
    new_node->data = new_data; 
    new_node->next = (*head_ref); 
    (*head_ref) = new_node; 
    //return ;
} 

int main()
{
    int n,m;
    scanf("%d",&n);
    struct node* head = NULL;
    struct node* p,*q;
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
    getRev(head);
}

/*
4
10 11 12 14
14 12 11 10
*/