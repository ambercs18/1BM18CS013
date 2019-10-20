#include<stdio.h>
#include<stdlib.h>
struct node
{
    int d;
    struct node* next;
};
typedef struct node* node;
node getnode()
{
    node p;
    p=(node)malloc(sizeof(struct node));
    return p;
}
node insertfront(node head,int e)
{
    node p=getnode();
    p->d=e;
    if(head==NULL)
    {
        p->next=p;
        return p;
}
else
{
    node q=head->next;
    while(q->next!=head)
        q=q->next;
    p->next=head;
    head=p;
    q->next=head;
    return head;
}
}
node insertend(node head,int e)
{
    node p=getnode();
    p->d=e;
    if(head==NULL)
    {
        p->next=p;
        return p;
    }
    else
    {
        node q=head->next;
        while(q->next!=head)
            q=q->next;
        q->next=p;
        p->next=head;
        return head;
    }
}
void show(node head)
{
    printf("%d ",head->d);
    node p=head->next;
    while(p!=head)
    {
        printf("%d ",p->d);
        p=p->next;

    }
}
node delfront(node head)
{
    if(head==NULL)
    {
        printf("Empty list\n");
        return NULL;
    }
    else if(head->next==head)
    {
      printf("Deleted element is %d\n",head->d);
    free(head);
    return NULL;
    }
    else
    {
        node p=head;
        node q=head->next;
        while(q->next!=head)
            q=q->next;
        q->next=head->next;
        printf("Deleted element is %d\n",head->d);
        head=head->next;
        free(p);
        return head;
    }
}
node delend(node head)
{
    node p=head;
    if(p==NULL)
    {
        printf("Empty List\n");
        return NULL;
    }
    else if(p->next==p)
    {
        printf("Deleted element is %d\n",p->d);
        free(p);
        return NULL;
    }
    else
    {
        node q=head;
        p=p->next;
        while(p->next!=head)
        {
            q=p;
            p=p->next;
        }
        printf("Deleted element is %d\n",p->d);
        q->next=p->next;
        free(p);
        return head;
    }
}
void search(node head,int e)
{
    int c=0;
    int f=0;
    if(head==NULL)
        printf("Empty list\n");
    else if(head->d==e)
    {
        printf("Element is present at %d position\n",c+1);
    }
    else
    {
        node p=head->next;
        while(p!=head)
        {
            if(p->d==e)
            {
                f=1;
                break;
            }
            p=p->next;
            c++;
        }
        if(f==1)
        {
            printf("Element is present at position %d\n",c+2);
        }
        else
            printf("NOt Present\n");

    }
}
node delval(node head,int e)
{
    int f=0;
    if(head==NULL)
    {
        printf("Empty List\n\n");
        return NULL;
    }
    else if(head->next==head&&head->d==e)
    {
        printf("Deleted element is %d\n",head->d);
        free(head);
        return NULL;
    }
    else if(head->d==e)
    {
        printf("Deleted element is %d\n",head->d);
        node p=head->next;
        node q=head;
        while(p->next!=head)
        {
            p=p->next;
        }
        head=q->next;
        p->next=head;
        free(q);
        return head;
    }
    else{
        node p=head->next;
        node q=head;;
        while(p!=head)
        {
            if(p->d==e)
            {
                f=1;
                break;
            }
            q=p;
            p=p->next;
        }
        if(f==1)
        {
        printf("Deleted element is %d\n",p->d);
        q->next=p->next;
        free(p);
        return head;
        }
        else
            printf("Not Found\n");
    }
}
node concat(node h1,node h2)
{
    if(h1==NULL)
        return h2;
    else if(h2==NULL)
        return h1;
    else{
        node p=h1->next;
        while(p->next!=h1)
            p=p->next;
        p->next=h2;
        p=h2->next;
        while(p->next!=h2)
            p=p->next;
        p->next=h1;
        return h1;
    }
}
void main()
{
    node head=NULL;
    node head2=NULL;
    int ch,ch1;
    int e;
    do
    {
        printf("Enter 1 to insert front\nEnter 2 to insert end\nEnter 3 to delete front\nEnter 4 to delete end\nEnter 5 to search a element\nEnter 6 to delete a value\nEnter 7 to insert at front in 2nd list\nEnter 8 to concat and display\nEnter 9 to show\n");
        scanf("%d",&ch);
        if(ch==1)
        {
            printf("Enter element\n");
            scanf("%d",&e);
            head=insertfront(head,e);
        }
        else if(ch==2)
        {
             printf("Enter element\n");
            scanf("%d",&e);
            head=insertend(head,e);

        }
        else if(ch==3)
        {
            head=delfront(head);
        }
        else if(ch==4)
            head=delend(head);
        else if(ch==5)
        {
            printf("Enter element\n");
            scanf("%d",&e);
            search(head,e);
        }
        else if(ch==6)
        {
            printf("Enter a value\n");
            scanf("%d",&e);
            head=delval(head,e);
        }
        else if(ch==7)
        {
            printf("Enter a element\n");
            scanf("%d",&e);
            head2=insertfront(head2,e);
        }
        else if(ch==8)
        {
            head=concat(head,head2);
            show(head);
        }
        else{
            show(head);
            printf("\n");
            show(head2);
        }

    printf("Enter 1 to continue and 2 to exit\n");
    scanf("%d",&ch1);
}while(ch1!=2);

}
