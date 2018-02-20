// Edit distance


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


int main() 
{
    
    int t,l1,l2,i,j;

    scanf("%d",&t);

    while(t--)

    {

	    string s1,s2;

	    cin >> s2 >> s1;

	    l1=s1.size();//to make another string like this

	    l2=s2.size();//converting string
 
	    int dp[2][l2+1];

	    for(i=0;i<1;i++)

	    {

	        for(j=0;j<=l2;j++)

	        {

	            dp[i][j]=j;

	            //cout << dp[i][j] << " " ;

	        }

	    }

	    dp[1][0]=1;

	    for(i=0;i<l1;i++)

	    {

	        for(j=0;j<l2;j++)

	        {

	            if(s1[i]==s2[j])

	            {

	                dp[1][j+1]=dp[0][j];

	            }

	            else

	            {

	                dp[1][j+1]=min(dp[0][j],dp[0][j+1]);

	                dp[1][j+1]=min(dp[1][j+1],dp[1][j])+1;

	            }

	        }

	        for(j=0;j<=l2;j++)

	        {

	            
dp[0][j]=dp[1][j];

	            //cout << dp[0][j]<< " ";

	        }

	        //cout << endl;

	        dp[1][0]=i+2;

	    }

	    cout << dp[1][l2]<<endl;

    }

    return 0;

}
