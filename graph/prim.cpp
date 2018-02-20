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
#include <stack>
#include <list>
#include <set>
#include <map>
#include <algorithm>

using namespace std;


int main(void)
{
	priority_queue<pair<int,int> , vector<pair<int,int> >,greater<pair<int,int> > > q;
	int n,vertex,u,v,weight;
	scanf("%d %d",&n,&vertex);
	vector<vector<int> > graph(vertex+1);
	int graph2D[vertex+1]][vertex+1] = {{0}};
	while(n--)
	{
		scanf("%d %d %d",&u,&v,&weight);
		graph2D[u][v]=weight;
	}
	return 0;
}