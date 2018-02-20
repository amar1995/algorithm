//stack
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <cctype>
using namespace std;

struct node 
{
    char data ;
    struct node *next=NULL;
};
void insert(node **h,char item)
{
    node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=item;
    newnode->next=NULL;
    
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
char pop(node **h)
{
    struct node *p=*h;
    *h=(*h)->next;
    char x=p->data;
    free(p);
    
    return x;
    
}
int isEmpty(node *h)
{
    if(h==NULL)
    return 1;
    else return 0;
}
char top_stack(node *h)
{
    char x=h->data;
    return x;
}
void display(node *h)
{
    while(h!=NULL)
    {
        printf("%s ",h->data);
        h=h->next;
    }
    printf("\n");
}
int main() {
    int n,i,j,p1,p2;
    char ch[100],a;
    string s="";
    char pre[]={'-','+','/','*','^'};
    //int pre[]={0,1,2,3};
    scanf("%s",ch);
    struct node *root=NULL;
    n=strlen(ch);
    i=0;
    while(i<n)
    {
        if(ch[i]!='+' and ch[i]!='*' and ch[i]!='/' and ch[i]!='-' and ch[i]!='(' and ch[i]!=')' and ch[i]!='^')
        {
            s+=ch[i];
            //cout << ch[i] << " ";
        }
        else
        {
            if(isEmpty(root))
            {
                insert(&root,ch[i]);
            }
            else
            {
                a=top_stack(root);
                if(ch[i]=='(')
                {
                    insert(&root,ch[i]);
                }
                else if(ch[i]==')')
                {
                    while(top_stack(root)!='(')
                    {
                        s+=pop(&root);
                    }
                    pop(&root);
                }
                else
                {
                    a=top_stack(root);
                    if(a=='(')
                    {
                        insert(&root,ch[i]);
                    }
                    else{
                    for(j=0;i<4;j++)
                    {
                        if(ch[i]==pre[j])
                        {
                            p1=j;
                            break;
                        }
                    }
                    for(j=0;i<4;j++)
                    {
                        if(a==pre[j])
                        {
                            p2=j;
                            break;
                        }
                    }
                    if(p1>p2)
                    {
                        insert(&root,ch[i]);
                    }
                    else
                    s+=ch[i];
                    }
                }
            }
        }
        i++;
    }
    while(!isEmpty(root))
    {
        s+=pop(&root);
    }
    cout << s << " ";
    return 0;
}
