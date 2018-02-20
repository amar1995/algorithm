// longest common subsequence in two string
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

int main() {
    int t,l1,l2,i,j;
    
	    string s1,s2;
	    cin >> s1 >> s2;
	    l1=s1.size();
	    l2=s2.size();
	    int dp[l1+1][l2+1];
	    for(i=0;i<=l2;i++)
	    {
	        for(j=0;j<=l2;j++)
	        dp[i][j]=0;
	    }
	    //cout << l1 << " " << l2;
	    for(i=0;i<l1;i++)
	    {
	        for(j=0;j<l2;j++)
	        {
	            if(s1[i]==s2[j])
	            {
	                dp[i+1][j+1]=dp[i][j]+1;
	            }
	            else
	            {
	                dp[i+1][j+1]=max(dp[i+1][j],dp[i][j+1]);
	            }
	            cout << dp[i+1][j+1] << " ";
	        }
	        cout << endl;
	    }
	    cout << dp[l1][l2];
	    
    
	return 0;
}
