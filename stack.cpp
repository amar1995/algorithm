//stack
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <cctype>
using namespace std;
int t=0;
struct node 
{
    int data = 0;
    struct node *next=NULL;
};
void push(node **h,int item)
{
    node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=item;
    newnode->next=NULL;
    t+=1;
    if(*h==NULL)
    {
        *h=newnode;
    }
    else
    {
        newnode->next=*h;
        *h=newnode;
    }
}
int delete_stack(node **h)
{
    struct node *p=*h;
    *h=(*h)->next;
    int x=p->data;
    free(p);
    t-=1;
    return x;
    
}
int top_stack(node *h)
{
    int x=h->data;
    return x;
}
void display(node *h)
{
    while(h!=NULL)
    {
        printf("%d ",h->data);
        h=h->next;
    }
    printf("\n");
}
int main() {
    int n,a,i;
    scanf("%d",&n);
    struct node *root=NULL;
    for(i=0;i<n;i++)
    {
        scanf("%d",&a);
        push(&root,a);
    }
    a=delete_stack(&root);
    printf("%d %d ",a,t);
    a=delete_stack(&root);
    printf("%d %d ",a,t);
    a=delete_stack(&root);
    printf("%d %d \n",a,t);
    a=top_stack(root);
    printf("%d %d \n",a,t);
    display(root);
    return 0;
}
