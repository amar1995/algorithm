//heap sort and priority queue
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
#define lli long long int 
#include <boost/multiprecision/cpp_int.hpp>
namespace mp = boost::multiprecision;
using namespace std;

inline int right(int a)
{
    return ((a<<1)+1);
}
inline int left(int a)
{
    return (a<<1);
}
inline int parent(int a)
{
    return (a>>1);
}
void swap(int *a,int *b)
{
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}
void max_heapify(int a[],int i,int n)
{
    if(left(i)<=n)
    {
        if(a[i]<a[left(i)])
        {
            if(right(i)<=n)
            {
                if(a[left(i)]<a[right(i)])
                {
                    swap(&a[right(i)],&a[i]);
                   return max_heapify(a,right(i),n);
                }
                else
                {
                    swap(&a[left(i)],&a[i]);
                   return max_heapify(a,left(i),n);
                }
            }
            else
            {
                swap(&a[left(i)],&a[i]);
                return max_heapify(a,left(i),n);
            }
        }
        else
        {
            if(right(i)<=n){
                
            
            swap(&a[right(i)],&a[i]);
            return max_heapify(a,right(i),n);}
            
        }
    }
}
void build_heap(int a[],int n)
{
    int i;
    for(i=n/2;i>=1;i--)
    {
        max_heapify(a,i,n);
        //cout << a[left(i)] << " " << a[right(i)] <<endl;
    }
}
void heap_sort(int a[],int n)
{
    int i;
    while(n>0)
    {
        swap(&a[n],&a[1]);
        n-=1;
        max_heapify(a,1,n);
    }
}
void extract_max(int a[],int n)
{
    int x=a[n];
    swap(&a[n],&a[1]);
    n-=1;
    max_heapify(a,1,n);
    return x;
}
inline void max(int a[])
{
    return a[1];
}
int main() {
    int a[]={0,2,3,2,1,4,6,5,9,7,8,0};
    int n=11;
    build_heap(a,n);
    heap_sort(a,n);
    for(int i=1;i<=n;i++)
    cout << a[i] << " ";
	return 0;
}
