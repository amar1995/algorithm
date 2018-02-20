// finding longest path in directed acyclic graph

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

void topSortUntil(vector<vector<int> > &graph,int visited[],stack<int> &topSort,int u)
{
	visited[u]=1;
	for(vector<int>::iterator v= graph[u].begin();v!=graph[u].end();v++)
		if(!visited[*v])
			topSortUntil(graph,visited,topSort,*v);
	topSort.push(u);
}

void topologicalSort(vector<vector<int > > &graph,int visited[],stack<int> &topSort,int vertex)
{
	for(int i=0;i<=vertex;i++)
	{
		if(!visited[i])
		topSortUntil(graph,visited,topSort,i);
	}
}

int main()
{
	int u,v,weight;//source and destination
	int n;//no of lines
	int vertex;//no of vertex
	scanf("%d %d",&n,&vertex);
	vector<vector<int > > graph(vertex+1);
	int graph2D[vertex+1][vertex+1]={{0}};
	int visited[vertex+1]={0};
	stack<int> topSort;
	for(int i=0;i<n;i++)
	{
		scanf("%d, %d, %d",&u,&v,&weight);
		graph[u].push_back(v);
		graph2D[u][v]=weight;
	}
	topologicalSort(graph,visited,topSort,vertex);
	/*
	while(!topSort.empty())
	{
	    cout << topSort.top() << " ";
	    topSort.pop();
	}*/
	//longest path in DAG
	
	int longestPath[vertex+1]={0};
	while(!topSort.empty())
	{
	    u=topSort.top();
		topSort.pop();
		for(vector<int>::iterator v = graph[u].begin();v!=graph[u].end();v++)
		{
			if(longestPath[*v]<longestPath[u]+graph2D[u][*v])
				longestPath[*v]=longestPath[u]+graph2D[u][*v];
		}
	}	
	for(int i=0;i<=vertex;i++)
		cout << longestPath[i] << " ";
	return 0;
}
