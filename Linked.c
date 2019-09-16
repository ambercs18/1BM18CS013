#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
typedef struct node* Node;
Node getnode()
{
    Node p;
    p=(Node)malloc(sizeof(struct node));
}
Node insertfront(int e,Node head)
{
    Node p;
    p=getnode();
    p->data=e;
    p->next=head;
    head=p;
    return head;
}
void show(Node head)
{
    Node p=head;
    while(p!=NULL)
    {
        printf("%d ",p->data);
        p=p->next;
    }
}
Node insert(Node head,int e,int pos)
{
    int c=0;
    Node p,q;
    q=getnode();
    if(pos==1)
    {
    insertfront(e,head);
    return head;
    }
    else
    {
    p=head;
        while((pos-2)!=c)
        {
            c++;
            p=p->next;    
        }
q->data=e;
        q->next=p->next;
        p->next=q;
        return head;
    }
    
}
Node insertval(Node head,int val,int e)
{
    Node p,q,r;
    int f,c=0;
    q=getnode();
    p=head;
    q->data=e;
    if(p->data==val)
    {
        q->next=head;
        head=q;
        return head;
    }
    while(p!=NULL)
    {
        if(p->data==val)
        {
            f=1;
            break;
        }
        r=p;
        p=p->next;
    }
    if(f==1)
    {
        r->next=q;
        q->next=p;
        return head;
    }
    else
    {
    printf("Value not present");
    return head;
    }
}

int main()
{
    Node head;
    head=NULL;
    head=insertfront(10,head);
head=insertfront(20,head);
head=insertfront(30,head);
head=insert(head,40,2);
head=insertval(head,30,1000);
    show(head);
    return 0;
}
