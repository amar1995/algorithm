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
void dfs(vector<vector<int > > &graph,int visited[],int u)
{
	visited[u]=1;
	//cout << u << " ";
	for(vector<int>::iterator v = graph[u].begin();v!=graph[u].end();v++)
		if(!visited[*v])
		{
		    dfs(graph,visited,*v);
		}
	cout << u << " ";
}
int main()
{
	int n,vertex;//number of lines
	scanf("%d %d",&n,&vertex);
	vector<vector<int> > graph(n+1);
	int visited[vertex+1]={0};
	while(n--)
	{
		int u,v;//source destination
		scanf("%d %d",&u,&v);
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	dfs(graph,visited,1);
	return 0;
}
