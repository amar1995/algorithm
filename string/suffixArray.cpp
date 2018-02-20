
//https://www.codechef.com/JAN18/problems/KILLKTH

#include <cstdio>
#include <cstdlib>
#include <string>
#include <iostream>
#include <cstring>
#include <climits>
#include <cctype>
#include <cstring>
#include <vector>
#include <queue>
#include <list>
#include <set>
#include <map>
#include <algorithm>
#define lli long long int 
#define mod 1000000007
using namespace std;

struct suffix
{
	int index;
	int rank[2];
};

int  compare(struct suffix a,struct suffix b)
{
	if(a.rank[0]==b.rank[0])
	{
		if(a.rank[1]<b.rank[1])
			return 1;
		else
			return 0;
	}
	else
	{
		if(a.rank[0]<b.rank[0])
			return 1;
		else
			return 0;
	}
}

int arr[200000+10];
int lcp[200000+10];
int times[200000+10];
int seg[1000000];
set<pair<int,int> > minIndex;
vector<vector<pair<int,int > > > range(200000+10);
lli ans[200000+10];
lli sum[200000+10];

void suffixArray(string s,int n)
{
	suffix suffixes[n];
	int i,k;
	for(i=0;i<n;i++)
	{
		suffixes[i].index=i;
		suffixes[i].rank[0]=(int)(s[i]-'a');
		suffixes[i].rank[1]=((i+1)<n )? int(s[i+1]-'a') : -1;
	}
	sort(suffixes,suffixes+n,compare);

	int currentIndex[n];
	for(k=4;k<2*n;k=k<<1)
	{
		int rank=0;
		int prevRank = suffixes[0].rank[0];
		suffixes[0].rank[0]=0;
		currentIndex[suffixes[0].index]=0;


		for(i=1;i<n;i++)
		{
			if((suffixes[i].rank[0]==prevRank) and(suffixes[i].rank[1]==suffixes[i-1].rank[1]))
			{
				prevRank=suffixes[i].rank[0];
				suffixes[i].rank[0]=rank;
			}
			else
			{
				prevRank=suffixes[i].rank[0];
				suffixes[i].rank[0]=++rank;
			}

			currentIndex[suffixes[i].index]=i;
		}
		for (i = 0; i < n; i++)
        {
            int nextindex = suffixes[i].index + (k>>1);
            suffixes[i].rank[1] = (nextindex < n)?
                                  suffixes[currentIndex[nextindex]].rank[0]: -1;
                                 // cout << suffixes[i].index << " ";
        }
        sort(suffixes,suffixes+n,compare);
        //cout << endl;
	}

	for(i=0;i<n;i++)
	{
		arr[i]=suffixes[i].index;
		//cout << suffixes[i].index << " ";
	}

}
void findLCP(int arr[],string s,int n)
{
    int k=0;
    int trank[n];
    for(int i=0; i<n; i++) trank[arr[i]]=i;

    for(int i=0; i<n; i++, k?k--:0)
    {
        if(trank[i]==n-1) {k=0; continue;}
        int j=arr[trank[i]+1];
        while(i+k<n && j+k<n && s[i+k]==s[j+k]) k++;
        lcp[trank[i]]=k;
    }
    int prev=lcp[0];
    for(int i=1;i<n;i++)
    {
        int temp=lcp[i];
        lcp[i]=prev;
        prev=temp;
    }
    lcp[0]=0;
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
void builtSegmentTree(int l,int r,int pos)
{
    if(l==r)
    {
        seg[pos]=lcp[l];
        return;
    }
    else{
        int mid=(l+r)/2;
        builtSegmentTree(l,mid,left(pos));
        builtSegmentTree(mid+1,r,right(pos));
        seg[pos]=min(seg[left(pos)],seg[right(pos)]);
    }
}
int find_min (int l,int r,int lq,int hq,int pos)
{
    if(lq>r or hq<l)
    return INT_MAX;
    if(lq<=l and hq>=r)
    {
        return seg[pos];
    }
    int mid=(l+r)/2;
    return min(find_min(l,mid,lq,hq,left(pos)),find_min(mid+1,r,lq,hq,right(pos)));
}


void makeRange(int n)
{
    int i;
    for(i=0;i<n-1;i++)
    {
        if(lcp[i]>lcp[i+1])
        continue;
        else
        {
            int min1=find_min(0,n-1,i+1,n-1,0);
            if(min1!=0 and lcp[i]<min1)
            {
                range[i].push_back(make_pair(min1,n-1));
            }
            int lastIndex = (lower_bound(minIndex.begin(),minIndex.end(),make_pair(min1,i+1)))->second-1;
            if(lastIndex==i)
            continue;
            while(lastIndex!=i+1)
            {
                min1=find_min(0,n-1,i+1,lastIndex,0);
                if(lcp[i]<min1)
                range[i].push_back(make_pair(min1,lastIndex));
                lastIndex = (lower_bound(minIndex.begin(),minIndex.end(),make_pair(min1,i+1)))->second-1;
            }
            min1=find_min(0,n-1,i+1,lastIndex,0);
            if(lcp[i]<min1)
            range[i].push_back(make_pair(min1,lastIndex));
        }
    }
}
lli make_sum(int a)
{
    return (lli)(((lli)((a+1)*a))/2);
}
void precompute(int n)
{
    int i,j;
    
    lli temp=0ll;
    int prev=lcp[i];
    for(i=0;i<n;i++)
    {
        lli size=(lli)(n-lcp[i]-arr[i]);
        prev=lcp[i];
        if(range[i].size()==0)
        {
            
            ans[i]=(lli)(((lli)lcp[i]*size)+(make_sum(size)));
            continue;
        }
        for(j=0;j<range[i].size();j++)
        {
            
            temp+=(lli)((lli)(range[i][j].second-i+1)*(make_sum(range[i][j].first)-make_sum(prev)));
            prev=range[i][j].first;
        }
        size=(lli)(n-prev-arr[i]);
        temp+=(lli)((lli)(prev*size)+(make_sum(size)));
        ans[i]=temp;
        temp=0ll;
    }
}
lli compute(int n,int i,lli k)
{
    int j;
    
    lli temp=0ll;
    lli size=(lli)(n-lcp[i]-arr[i]);
    int prev=lcp[i];
    if(range[i].size()==0)
    {
        
        for(j=lcp[i]+1;j<=size;j++)
        if(k>(lli)j)
        k-=(lli)j;
        else
        break;
        return k+(lli)arr[i];
    }
    for(j=0;j<range[i].size();j++)
    {
        
        temp=(lli)((lli)(range[i][j].second-i+1)*(make_sum(range[i][j].first)-make_sum(prev)));
        if(k>temp)
        k-=temp;
        else
        break;
        
        prev=range[i][j].first;
    }
    
    if(j==range[i].size())
    {
        size=(lli)(n-arr[i]);
        
        for(j=prev+1;j<size;j++)
        if(k>(lli)j)
        k-=(lli)j;
        else
        {
            break;
        }
        
        return k+(lli)arr[i];
    }
    size=(lli)range[i][j].first;
    lli rep=(lli)(range[i][j].second-i+1);
    for(lli l=(lli)prev+1ll;l<=size;l++)
    {
        if(k>rep*l)
        k-=rep*l;
        else
        {
            //cout << k << " ";
            rep-=1;
            if(rep==1)
            {
                if(k>rep*l)
                k-=rep*l;
                return k+(lli)arr[i];
            }
            while(rep>1)
            {
                if(k>rep*l)
                {
                    k-=rep*l;
                    return k+(lli)arr[i];
                }
                rep--;
            }
        }
    }
    temp=0ll;
}
int main()
{
	string s;
	cin >> s;
	int n = s.size();
	suffixArray(s,n);
	findLCP(arr,s,n);
	/*for(int i=0;i<n;i++)
	cout << arr[i] << " ";
	cout << endl;
	for(int i=0;i<n;i++)
	cout << lcp[i] << " ";
	cout << endl;*/
	for(int i=0;i<n;i++)
	minIndex.insert(make_pair(lcp[i],i));
	builtSegmentTree(0,n-1,0);
	//cout << find_min(0,n-1,1,9,0) << " ";
    //cout << (lower_bound(minIndex.begin(),minIndex.end(),make_pair(3,16)))->second << endl;
	makeRange(n);
	precompute(n);
	sum[0]=ans[0];
	for(int i=1;i<n;i++)
	{
	    /*cout << i << " ";
	    for(int j=0;j<range[i].size();j++)
	    cout << range[i][j].first << " ";
	    cout << endl;*/
	    sum[i]=ans[i]+sum[i-1];
	}
	//input
	
	int q;
	lli g=0ll;
	scanf("%d",&q);
	while(q--)
	{
	    lli p,m,k;
	    
	    scanf("%lld %lld",&p,&m);
	    k=(p*g)%m+1;
	    //cout << k << " ";
	    int index = upper_bound(sum,sum+n,k)-sum;
	    if(index>0)
	    k-=sum[index-1];
	    lli x=compute(n,index,k)-1ll;
	    char val = s[x];
	    g=(lli)(val);
	    //cout << g << " ";
	    cout <<  val << endl;
	}
	return 0;
}
