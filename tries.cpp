#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <climits>
#include <queue>
#include <set>
#define mod 1000000007

using namespace std;
#define lli long long int 

struct tries
{
	struct tries *arr[26];
	bool condition;
	int value[26];
};
struct tries *create()
{
	struct tries *p=(struct tries *)malloc(sizeof(struct tries));
	for(int i=0;i<26;i++)
	{
		p->arr[i]=NULL;
		p->value[i]=0;
	}
	
	p->condition=false;
	
	return p;
}
void insert(tries **h,string s,int val,int len)
{
	struct tries *p=*h;
	for(int i=0;i<len;i+=1)
	{
		if(p->arr[(int)s[i]-97]==NULL)
		{
		    
			p->arr[(int)s[i]-97]=create();
			p->value[(int)s[i]-97]=val;
		}
		else
		{
			p->value[(int)s[i]-97]=max(p->value[(int)s[i]-97],val);
			
		}
		p=p->arr[(int)s[i]-97];
	}
	p->condition=true;
}
int search(tries *p,string s,int len)
{
	for(int i=0;i<len-1;i++)
	{
	    if(p->arr[(int)s[i]-97]!=NULL)
		p=p->arr[(int)s[i]-97];
		else
		return -1;
	}
	if(p->value[(int)s[len-1]-97]!=NULL)
	return p->value[(int)s[len-1]-97];
	else
	return -1;
}
int main()
{
    int n,i,l,q;
    tries *root=create();
    scanf("%d %d",&n,&q);
    for(i=0;i<n;i++)
    {
    	string s;
    	int a;
    	cin >> s >> a;
    	l=s.size();
    	insert(&root,s,a,l);
    }
    while(q--)
    {
    	string s;
    	cin >> s;
    	l=s.size();
    	printf("%d\n",search(root,s,l));
    }
    return 0;
}
