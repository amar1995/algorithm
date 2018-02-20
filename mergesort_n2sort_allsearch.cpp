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
using namespace std;
#define mod 1000000007
#define lli long long int 
void swap(int *a,int *b)
{
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}
void merge(int arr[],int l,int m,int r)
{
    int n1=m-l+1,i;
    int n2=r-m;
    int a[n1],b[n2];
    for(i=0;i<n1;i++)
    a[i]=arr[l+i];
    for(i=0;i<n2;i++)
    b[i]=arr[m+1+i];
    int k=l,j=0;
    i=0;
    while(j<n1 and i<n2)
    {
        if(a[j]<b[i])
        {
            arr[k]=a[j];
            k++;j++;
        }
        else
        {
            arr[k]=b[i];
            i++;
            k++;
        }
        
    }
    while (i < n2)
    {
        arr[k] = b[i];
        i++;
        k++;
    }
 
    /* Copy the remaining elements of R[], if there
       are any */
    while (j < n1)
    {
        arr[k] = a[j];
        j++;
        k++;
    }
}
void merge_sort(int arr[],int l,int r)
{
    if(l<r){
    int mid=(l+r)/2;
    merge_sort(arr,l,mid);
    merge_sort(arr,mid+1,r);
    merge(arr,l,mid,r);
    }
}
int upper_bound(int arr[],int k,int l,int r)
{//printf("%d ",r);
    if(l<r)
    {
        int mid=(l+r)/2;
        if(arr[mid]==k)
        return mid;
        else if(arr[mid]>k)
        upper_bound(arr,k,l,mid);
        else
        upper_bound(arr,k,mid+1,r);
    }
    else return arr[r];
}
int lower_bound(int arr[],int k,int l,int r)
{//printf("%d ",r);
    if(l<r)
    {
        int mid=(l+r)/2;
        if(arr[mid]==k)
        return mid;
        else if(arr[mid]>k)
        lower_bound(arr,k,l,mid);
        else
        lower_bound(arr,k,mid+1,r);
    }
    else if(l==r)
    {
        if(arr[l]==k)
        return arr[l];
        else return arr[l-1];
    }
    else
    return arr[l];
}
bool binary_search(int arr[],int k,int l,int r)
{//printf("%d ",r);
    if(l<r)
    {
        int mid=(l+r)/2;
        if(arr[mid]==k)
        return true;
        else if(arr[mid]>k)
        binary_search(arr,k,l,mid);
        else
        binary_search(arr,k,mid+1,r);
    }
    else if(l==r)
    {
        if(arr[l]==k)
        return true;
        else return false;
    }
    else
    return false;
}
bool exponential_search(int arr[],int k,int n)
{
    if(n==0)
    return false;
    int bound =1;
    while(bound < n )
    {
        if(arr[bound-1]<k)
        bound <<=1;
        else
        break;
    }
    //printf("%d ",bound);
    bool f=binary_search(arr,k,(bound>>1)-1,min(bound,n)-1);
    //return f;
}
bool interpolation_search(int arr[],int k,int l,int r)
{
    if(l<=r)
    {
       int mid=((r-l)*(k-arr[l]))/(arr[r]-arr[l])+l;
       if(arr[mid]==k)
       return true;
       else if(arr[mid]>k)
       interpolation_search(arr,k,l,mid-1);
       else
       interpolation_search(arr,k,mid+1,r);
    }
    else
    return false;
}
void bubble_sort(int arr[],int n)
{
    int i,j,flag;
    for(i=0;i<n;i++)
    {
        flag=1;
        for(j=1;j<n-i;j++)
        {
            if(arr[j]<arr[j-1])
            {
                swap(arr[j],arr[j-1]);
                flag=0;
            }
        }
        if(flag)
        break;
    }
}
void insertion_sort(int arr[],int n)
{
    int i,j,key;
    for(i=1;i<n;i++)
    {
        j=i-1;
        key=arr[i];
        while(j>=0 and arr[j]>key)
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
}
void selection_sort(int arr[],int n)
{
    int i,j,m,pos;
    for(i=0;i<n;i++)
    {
        m=arr[i];pos=i;
        for(j=i+1;j<n;j++)
        {
            if(m>arr[j])
            {
                m=arr[j];
                pos=j;
            }
        }
        swap(arr[pos],arr[i]);
    }
}
int main(void)
{
    int n,i,key;
    scanf("%d",&n);
    int arr[n];
    for(i=0;i<n;i++)
    scanf("%d",arr+i);
    //merge_sort(arr,0,n-1);
    //bubble_sort(arr,n);
    //insertion_sort(arr,n);
    selection_sort(arr,n);
    for(i=0;i<n;i++)
    printf("%d ",arr[i]);
    scanf("%d",&key);
    if(exponential_search(arr,key,n))
    printf("Y\n");
    else
    printf("N\n");
    printf("%d ",lower_bound(arr,10,0,n-1));
    return 0;
}