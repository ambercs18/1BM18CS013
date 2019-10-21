#include<stdio.h>
#include<stdlib.h>
struct node{
int d;
struct node* next;
struct node* prev;};
typedef struct node* node;
node getnode()
{
    node p=(node)malloc(sizeof(struct node));
    return p;
}
node insertfront(node head,int e)
{
    node p=getnode();
    p->d=e;
    p->next=NULL;
    p->prev=NULL;
    if(head==NULL)
        return p;
    else
    {
        p->next=head;
        head->prev=p;
        p->prev=NULL;
        head=p;
        return head;
    }
}
node insertend(node head,int e)
{
    node p=getnode();
    p->d=e;
    p->prev=NULL;
    p->next=NULL;
    if(head==NULL)
        return p;
    else{
        node q=head;
        while(q->next!=NULL)
            q=q->next;
        q->next=p;
        p->prev=q;
        return head;
    }
}
void show(node head)
{
    if(head==NULL)
        printf("Empty LIst\n");
    else{
        node p=head;
        while(p!=NULL)
        {
            printf("%d ",p->d);
            p=p->next;
        }
    }
}
node delfront(node head)
{
    if(head==NULL)
    {
        printf("LIst is Empty\n");
        return NULL;
    }
    else if(head->next==NULL)
    {
        printf("Deleted element is %d\n",head->d);
        free(head);
        return NULL;
    }
    else
    {
        printf("Deleted element is %d\n",head->d);
        node p=head;
        head=head->next;
        head->prev=NULL;
        free(p);
        return head;
    }
}
node delend(node head)
{
    if(head==NULL)
    {
        printf("Empty LIst\n");
        return NULL;
    }
    else if(head->next==NULL)
    {
        printf("Deleted element is %d\n",head->d);
        free(head);
        return NULL;
    }
    else{
        node p=head;
        while(p->next!=NULL)
            p=p->next;
        printf("Deleted element is %d\n",p->d);
        p->prev->next=NULL;
        free(p);
        return head;
    }
}
node delval(node head,int v)
{
    int f=0;
    if(head==NULL)
    {
        printf("Empty list\n");
        return NULL;
    }
   else if(head->d==v&&head->next==NULL)
    {
        printf("Deleted element is %d\n",head->d);
        free(head);
        return NULL;
    }
    else if(head->d==v)
    {
        node p=head;
        printf("Deleted element is %d\n",head->d);
        head=head->next;
        free(p);
        return head;
    }
    else{
        node p=head;
        while(p->next!=NULL)
        {
            if(p->d==v)
            {
                f=1;
                break;
            }
            p=p->next;
        }
        if(f==1){
        printf("Deleted element is %d\n",p->d);
        p->next->prev=p->prev;
        p->prev->next=p->next;
        }
        else if(p->d==v)
        {
            printf("Deleted element is %d\n",p->d);
            p->prev->next=NULL;
            free(p);
            return head;
        }
        else
            printf("Value not found\n");
    }
}
void search(node head,int e)
{
    if(head==NULL)
        printf("List is Empty\n");
    int c=0;
    int f=0;
    node p=head;
    while(p!=NULL)
    {
        c++;
        if(p->d==e)
        {
            f=1;
            break;
        }
        p=p->next;
    }
    if(f==1)
    {
        printf("Element was found at node %d\n",c);
    }
    else
        printf("Not Found\n");
}
void main()
{
    node h=NULL;
    int ch,ch1,e;
    do
    {
        printf("Enter 1 to insert front\nEnter 2 to insert end\nEnter 3 to delete front\nEnter 4 t0 delete end\nEnter 5 to delete a value\nEnter 6 to search a value\nEnter 7 to display list\n");
        scanf("%d",&ch);
        if(ch==1)
        {
            printf("Enter element\n");
            scanf("%d",&e);
            h=insertfront(h,e);
        }
        else if(ch==2)
        {
            printf("Enter element\n");
            scanf("%d",&e);
            h=insertend(h,e);
        }
        else if(ch==3)
        {
            h=delfront(h);
        }
        else if(ch==4)
            h=delend(h);
        else if(ch==5)
        {
            printf("Enter a value\n");
            scanf("%d",&e);
            h=delval(h,e);
        }
        else if(ch==6)
        {
            printf("Enter a value\n");
            scanf("%d",&e);
            search(h,e);
        }
        else
            show(h);
        printf("Enter 1 to continue and 2 to exit\n");
        scanf("%d",&ch1);
    }while(ch1!=2);
}

