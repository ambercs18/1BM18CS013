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
Node push(int e,Node head,int *c)
{
    if(*c<=3)
    {
    Node p;
    p=getnode();
    p->data=e;
    p->next=head;
    head=p;
    return head;
    }
    else
    {
    printf("Stack Overflow \n");
    return head;
    }
}
Node pop(Node head)
{  
    Node p=head;
    if(head==NULL)
    {
      printf("Stack Underflow \n");
      return head;
     }
    printf("Popped element is = %d \n",p->data);
    head=head->next;
    free(p);
    return head;
}
void display(Node head)
{
 Node p;
 p=head;
 if(p==NULL)
 printf("Stack is Empty \n");
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
 int e;
 int c=0;
 Node head;
 head=NULL;
 int ch,ch1;
 do
 {
  printf("Enter 1 to push element on stack\nEnter 2 to pop a element\nEnter 3 to display\n");
  scanf("%d",&ch);
  if(ch==1)
  {
   printf("Enter the element\n");
   scanf("%d",&e);
   c++;
   head=push(e,head,&c); 
  }
  else if(ch==2)
  {
   head=pop(head);
  }
  else
  display(head);
  printf("Enter 1 to continue and 0 to exit\n");
  scanf("%d",&ch1);
 }while(ch1!=0);
}
