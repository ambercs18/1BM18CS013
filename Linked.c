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
void insertend(Node head,int item)
{
    Node p,q;
    q=getnode();
    q->data=item;
    p=head;
    while(p->next!=NULL)
    {
       p=p->next;
       }
    p->next=q;
    q->next=NULL;
}
void show(Node head)
{
    Node p=head;
    if(p==NULL)
    printf("List is empty\n");
    else
    {
    while(p!=NULL)
    {
        printf("%d\n",p->data);
        p=p->next;
    }
    }
}
Node insert(Node head,int e,int pos)
{
    int c=1;
    Node p,q,r;
    q=getnode();
    q->data=e;
    if(head==NULL)
    {
       if(pos==1)
       return q;
    else
    {
       printf("Inalid Position \n");
       return head;
     }
    }
    if(pos==1)
    {
       q->next=head;
       head=q;
       return head;
     }
    else{
         r=head;
         while(r!=NULL && c!=pos)
         {
            p=r;
            r=r->next;
            c++;
         }
        if(c==pos)
        {
          p->next=q;
          q->next=r;
          return head;
        }
        else{
             printf("Invalid Position\n");
             return head;
             }
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
Node delfront(Node head)
{  
    Node p=head;
    if(head==NULL)
    {
      printf("List is Empty \n");
      return head;
     }
    printf("Deleted element is = %d \n",p->data);
    head=head->next;
    free(p);
    return head;
}
void delend(Node head)
{
   Node p,r;
   p=head;
   if(head==NULL)
   printf("List is Empty \n");
   else
   {
   while(p->next!=NULL)
   {
     r=p;
     p=p->next;
   }
   printf("Deleted element is = %d",p->data);
   r->next=NULL;
   free(p);
   }
}
Node delval(Node head,int val)
{
   Node p,r;
   int f;
   p=head;
   if(head==NULL)
   {
     printf("List is Empty \n");
     return head;
   }
   else if(head->data==val)
   {
      head=delfront(head);
      return head;
   }
   else
   {
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
    }
     if(f==1)
     {
     printf("Deleted element is = %d\n",p->data);
     r->next=p->next;
     free(p);
     return head;
     }
     else
     {
     printf("Element not found\n");
     return head;
     }
}      
int main()
{
    Node head;
    head=NULL;
    int ch,ch1,e,p,v;
    do{
        printf("Enter 1 to add node at front\nEnter 2 to add node at end\nEnter 3 to add node at any position\nEnter 4 delete the front element\nEnter 5 to delete last element\nEnter 6 to delete a value\nEnter 7 to display\n");
        scanf("%d",&ch); 
        switch(ch)
        {
           case 1:
   
                  printf("Enter element to be inserted \n");
                  scanf("%d",&e);
                  head=insertfront(e,head);
                  break;
           case 2:
           
           printf("Enter element to be inserted\n");
           scanf("%d",&e);
           insertend(head,e);
           break;
           case 3:
            
           printf("Enter element to be inserted and position\n");
           scanf("%d%d",&e,&p);
           head=insert(head,e,p);
           break;
           case 4:
                  head=delfront(head);
                  break;
           case 5:
                  delend(head);
                  break; 
           case 6:
                  printf("Enter value to be deleted\n");
                  scanf("%d",&v);
                  head=delval(head,v);
                  break; 
           case 7:
           show(head);
           break;
           }
           printf("Enter 1 to continue and 0 to exit\n");
           scanf("%d",&ch1);
           }while(ch1!=0);
   return 0;
}
