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
Node insert(Node head,int item,int *c)
{
    if(*c<=3)
    {
    Node p,q;
    q=getnode();
    q->data=item;
    p=head;
    if(p==NULL)
    return q;
    else
    {
    while(p->next!=NULL)
    {
       p=p->next;
       }
    p->next=q;
    q->next=NULL;
    return head;
    }
    }
    else
    {
    printf("Queue Overflow\n");
    return head;
    }
}
Node del(Node head)
{  
    Node p=head;
    if(head==NULL)
    {
      printf("Queue Underflow \n");
      return head;
     }
    printf("Deleted element is = %d \n",p->data);
    head=head->next;
    free(p);
    return head;
}
void show(Node head)
{
    Node p=head;
    if(p==NULL)
    printf("Queue is empty\n");
    else
    {
    while(p!=NULL)
    {
        printf("%d\n",p->data);
        p=p->next;
    }
    }
}
void main()
{
  Node head=NULL;
  int ch,ch1;
  int e;
  int c=0;
  do
  {
    printf("Enter 1 to insert\nEnter 2 to delete\nEnter 3 to show\n");
    scanf("%d",&ch);
    if(ch==1)
    {
      printf("Enter element\n");
      scanf("%d",&e);
      c++;
      head=insert(head,e,&c);
    }
    else if(ch==2)
    {
      head=del(head);
    }
    else
    show(head);
    printf("Enter 1 to continue or 0 to exit\n");
    scanf("%d",&ch1);
  }while(ch1!=0);
}
     
      
  

