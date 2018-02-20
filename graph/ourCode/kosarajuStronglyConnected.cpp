//finding strongly connected graph in DAG

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

void dfsUntil(vector<vector<int> > &graph,int visited[],int u)
{
	visited[u]=1;
	for(vector<int>::iterator v=graph[u].begin();v!=graph[u].end();v++)
	{
		if(!visited[*v])
			dfsUntil(graph,visited,*v);
	}
}

bool stronglyConnected(vector<vector<int> > &graph,vector<vector<int> > &reverseGraph,int visited[],int vertex)
{

	dfsUntil(graph,visited,0);
	for(int i=0;i<=vertex;i++)
	{
		if(visited[i])
		{
			visited[i]=0;
		}
		else return false;
	}
	dfsUntil(reverseGraph,visited,0);
	for(int i=0;i<=vertex;i++)
	{
		if(!visited[i])
		return false;
	}
	return true;
}

int main(void)
{
	int n,vertex,u,v;
	scanf("%d %d",&n,&vertex);
	vector<vector<int> > graph(vertex+1);
	vector<vector<int> > reverseGraph(vertex+1);
	int visited[vertex+1]={0};
	while(n--)
	{
		scanf("%d %d",&u,&v);
		graph[u].push_back(v);
		reverseGraph[v].push_back(u);
	}
	if(stronglyConnected(graph,reverseGraph,visited,vertex))
		cout << "Yes";
	else
		cout << "No";
	return 0;
}