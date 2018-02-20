//mother vertex is a vertex from where we can reach to every vertex

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

void dfsUntil(vector<vector<int> > &graph,int visited[],int u)
{
    visited[u]=1;
	for(vector<int>::iterator v = graph[u].begin();v!=graph[u].end();v++)
		if(!visited[*v])
			dfsUntil(graph,visited,*v);
}

void dfs(vector<vector<int> > &graph,int visited[],int vertex)
{
	int lastvisit;
	for(int i=0;i<=vertex;i++)
	{
		if(!visited[i])
		{
		    dfsUntil(graph,visited,i);
	        lastvisit = i;
	        //cout << i << endl;
		}
	}
	cout << lastvisit << endl;
}

int main()
{
	int n,vertex;//number of lines
	scanf("%d %d",&n,&vertex);
	vector<vector<int> > graph(n+1);
	//Directed Acyclic graph
	int visited[vertex+1]={0};
	while(n--)
	{
		int u,v;//source destination
		scanf("%d %d",&u,&v);
		graph[u].push_back(v);
	}
    dfs(graph,visited,vertex);
	return 0;
}
