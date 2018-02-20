#include<iostream>
#include<stdio.h>
#include<cmath>
#include<cstring>
#include<stdlib.h>
#include<algorithm>
#include<limits.h>
#include<list>
using namespace std;
#define getcx getchar
#define lli long long int
#define MAX 1000001
bool v[MAX];
int len, sp[MAX]={0,1,0};

inline int in()
{
   int n=0;
   int ch=getcx();int sign=1;
   while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getcx();}
 
   while(  ch >= '0' && ch <= '9' )
           n = (n<<3)+(n<<1) + ch-'0', ch=getcx();
   return n*sign;
}
int powerOf2(int a)
{
    a-=1;
    a=a|(a>>1);
    a=a|(a>>2);
    a=a|(a>>4);
    a=a|(a>>8);
    a=a|(a>>16);
    return a+1;
}
void Sieve(){
	for (int i = 2; i < MAX; i += 2)	sp[i] = 2;//even numbers have smallest prime factor 2
	for (lli i = 3; i < MAX; i += 2){
		if (!v[i]){
			sp[i] = i;
			for (lli j = i; (j*i) < MAX; j += 2){
				if (!v[j*i])	v[j*i] = true, sp[j*i] = i;
			}
		}
	}
}
inline int left(int a)
{
    return (a<<1)+1;
}
inline int right(int a)
{
    return ((a<<1)+2);
}
inline int parent(int a)
{
    return ((a-1)>>1);
}
void builtSegmentTree(int seg[],int arr[],int l,int r,int pos,int keep[])
{
    if(l==r)
    {
        seg[pos]=sp[arr[l]];
        keep[l]=pos;
        return;
    }
    else{
        int mid=(l+r)/2;
        builtSegmentTree(seg,arr,l,mid,left(pos),keep);
        builtSegmentTree(seg,arr,mid+1,r,right(pos),keep);
        seg[pos]=max(seg[left(pos)],seg[right(pos)]);
    }
}
void updateSegmentTree(int seg[],int pos)
{
    //cout << 1 << " ";
    if(pos==0){
        
        seg[pos]=max(seg[left(pos)],seg[right(pos)]);
        return;
    }
    else
    {
        int z=seg[pos];
        seg[pos]=max(seg[left(pos)],seg[right(pos)]);
        if(seg[pos]==z)
        return;
        else
        updateSegmentTree(seg,parent(pos));
    }
}
int find_max(int seg[],int l,int r,int lq,int hq,int pos)
{
    if(lq>r or hq<l)
    return INT_MIN;
    if(lq<=l and hq>=r)
    {
        return seg[pos];
    }
    int mid=(l+r)/2;
    return max(find_max(seg,l,mid,lq,hq,left(pos)),find_max(seg,mid+1,r,lq,hq,right(pos)));
}
int main()
{
    Sieve();
	int t,i,n,m,x,j,l,r,z;
	t=in();
	while(t--)
	{
	    n=in();m=in();
	    int arr[n];
	    for(i=0;i<n;i++)
	    {
	        arr[i]=in();
	    }
	
	    int seg[powerOf2(n)*2+1];
	    //cout << powerOf2(4) << " ";
	    int keep[n];
	    builtSegmentTree(seg,arr,0,n-1,0,keep);
	    while(m--)
	    {
	        
	        z=in();l=in();r=in();
	        if(z==0)
	        {
	            for(i=l-1;i<r;i++)
	            {
	                if(arr[i]!=1){
	                int x=sp[arr[i]];
	                arr[i]/=x;
	                if(sp[arr[i]]!=x)
	                {
	                        seg[keep[i]]=sp[arr[i]];
	                        updateSegmentTree(seg,parent(keep[i]));
	                }
	                }
	            }
	        }
	        else
	        {
	            
	            printf("%d ",find_max(seg,0,n-1,l-1,r-1,0));
	        }
	    }
	    printf("\n");
	}
	return 0;
}