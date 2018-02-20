// AVL TREE

#include <cmath>
#include <cstdio>
#include <climits>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <cctype>
#define lli long long int
using namespace std;
struct node
{
    int data = 0;
    int height = 0;
    struct node *left = NULL;
    struct node *right = NULL;
};
struct node *newnode(int item)
{
    struct node *h=(struct node *)malloc(sizeof(struct node));
    h->data=item;
    h->height=1;
    h->left=NULL;
    h->right=NULL;
    return h;
}
int height(struct node *h)
{
    if(h==NULL)
    return 0;
    else
    return h->height;
}
struct node *rightRotate(struct node *root)
{
    struct node *temp1=root->left;
    root->left=temp1->right;
    temp1->right=root;
    temp1->height=max(height(temp1->right),height(temp1->left))+1;
    root->height=max(height(root->left),height(root->right))+1;
    return temp1;
}
struct node *leftRotate(struct node *root)
{
    struct node *temp1=root->right;
    root->right=temp1->left;
    temp1->left=root;
    temp1->height=max(height(temp1->right),height(temp1->left))+1;
    root->height=max(height(root->left),height(root->right))+1;
    return temp1;
}
struct node *insert(struct node *h,int item)
{
    if(h==NULL)
    {
        h=newnode(item);
        return h;
    }
    else if(h->data > item)
    {
        h->left=insert(h->left,item);
    }
    else
    {
        h->right=insert(h->right,item);
    }
    h->height=max(height(h->right),height(h->left))+1;
    int balance=height(h->left)-height(h->right);
    if(balance>1)
    {
        if(height(h->left->left)>=height(h->left->right))//left left rotation
        {
            h=rightRotate(h);
            return h;
        }
        else //left right rotation 
        {
            h->left=leftRotate(h->left);
            return (rightRotate(h));
        }
    }
    else if(balance<-1)
    {
        if(height(h->right->right)>=height(h->right->left))
        return (leftRotate(h));
        else
        {
            h->right=rightRotate(h->right);
            return leftRotate(h);
        }
    }
    return h;
}
void inOrder(struct node *root)
{
    if(root != NULL)
    {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}
int main() {
    int t,l1,l2,i,j,n;
    scanf("%d",&t);
    struct node *root=NULL;
    while(t--)
    {
	   scanf("%d",&n);
	   root=insert(root,n);
    }
    inOrder(root);
	return 0;
}
