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

using namespace std;

int main()
{
	int t,i,n,j;
	scanf("%d",&t);
	while(t--)
	{
		int sum=0;
		scanf("%d",&n);
		int arr[n];
		for(i=0;i<n;i++)
		{
			scanf("%d",arr+i);
			sum+=arr[i];
		}   
		int sum1=sum;
		//cout << sum1 << endl;
		if(sum&1)
			sum=sum/2+1;
		else
			sum=sum/2;
		int dp[n+1][sum+1];
		for(i=0;i<=n;i++)
        {
            for(j=0;j<=sum;j++)
            dp[i][j]=0;
        }
		for(i=1;i<=n;i+=1)
		{
			for(j=0;j<=sum;j++)
			{
			    if(j<arr[i-1])
			    {
			        dp[i][j]=dp[i-1][j];
			        continue;
			    }
			    else 
			    {
			        dp[i][j]=max(dp[i-1][j],dp[i-1][j-arr[i-1]]+arr[i-1]);
			        continue;
			    }
				
			}
		}
		int ans;
		
        ans=abs(sum1-2*dp[n][sum]);
        cout << ans << endl;
	}
	return 0;
}