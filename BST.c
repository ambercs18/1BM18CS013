#include<stdio.h>
#include<stdlib.h>
#include<math.h>
struct node
{
  int d;
  struct node* left;
  struct node* right;
};
typedef struct node* node;
node getnode()
{
  node p=(node)malloc(sizeof(struct node));
  return p;
}
node insert(node r,int v)
{
  node n=getnode();
  n->left=NULL;
  n->right=NULL;
  n->d=v;
  if(r==NULL)
  {
  return n;
  }
  else
  {
    node p=r;
    node q=NULL;
    while(p!=NULL)
    {
      q=p;
      if(p->d>v)
      p=p->left;
      else
      p=p->right;
     }
     if(q->d>v)
     q->left=n;
     else
     q->right=n;
     return r;
    }
}
void inorder(node r)
{
  if(r==NULL)
  return;
  inorder(r->left);
  printf("%d ",r->d);
  inorder(r->right);
}
void preorder(node r)
{
  if(r==NULL)
  return;
  printf("%d ",r->d);
  preorder(r->left);
  preorder(r->right);
}
void postorder(node r)
{
  if(r==NULL)
  return;
  postorder(r->left);
  postorder(r->right);
  printf("%d ",r->d);
}
void showl(node r)
{
 if(r==NULL)
 printf("Empty tree\n");
 else
 {
  int i=0;
  while(1)
  {
    if(r->left!=NULL)
    {
     printf("Level %d- %d,",i,r->d);
    }
    if(r->right!=NULL)
    {
      printf(" %d,",r->d);
    }
    else if(r->left==NULL&&r->right==NULL)
    break;
    else
    {
      r=r->left;
      r=r->right;
      i++;
    }
   }
  }
}
node min(node r)
{
  node p=r;
  int m=9999;
  node n=NULL;
  while(p!=NULL)
  {
   if(m>p->d)
   {
     m=p->d;
     n=p;
   }
   p=p->left;
  }
  return n;
}
node del(node r,int k)
{
  if(r==NULL)
  return r;
  if(k<r->d)
  r->left=del(r->left,k);
  else if(k>r->d)
  r->right=del(r->right,k);
  else
  {
   if(r->left==NULL)
   {
     node t=r->right;
     free(r);
     return t;
   }
   else if(r->right==NULL)
   {
     node t=r->right;
     free(r);
     return t;
   }
   node t=min(r->right);
   r->d=t->d;
   r->right=del(r->right,t->d);
   }
  return r;
}  
void printGivenLevel(struct node* r, int hm) 
{ 
    if (r == NULL) 
        return; 
    if (hm == 1) 
        printf("%d ", r->d); 
    else if (hm > 1) 
    { 
        printGivenLevel(r->left, hm-1); 
        printGivenLevel(r->right, hm-1); 
    } 
} 
void printLevelOrder(struct node* r,int h) 
{ 
    int i; 
    for (i=1; i<=h; i++) 
    { 
        printGivenLevel(r, i); 
        printf("\n"); 
    } 
} 
void main()
{
  double i=0;
  int ch,ch1,e;
  node r=NULL;
  do
  {
    printf("Enter 1 to insert\nEnter 2 to display inorder\nEnter 3 to display preorder\nEnter 4 to display postorder\nEnter 5 to show hieght\n");
    scanf("%d",&ch);
    if(ch==1)
    {
     printf("Enter element\n");
     scanf("%d",&e);
     i++;
     r=insert(r,e);
    }
    else if(ch==2)
    inorder(r);
    else if(ch==3)
    preorder(r);
    else if(ch==4)
    postorder(r);  
    else
    {
     double a=log(i+1);
     double b=log(2);
     double h=(a/b)-1;
     int hm=(int)h+i;
     printLevelOrder(r,hm);
    }
    printf("Enter 1 to continue and 2 to exit\n");
    scanf("%d",&ch1);
   }while(ch1!=2);
}
 
