// Closure in a graph is a abilty to reach u to v in a graph
//The reach-ability matrix is called transitive closure of a graph.

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

int closure[100][100];

void dfsUntil(vector<vector<int> > &graph,int visited[],int u,int preu)
{
    visited[u]=1;
    
	for(vector<int>::iterator v = graph[u].begin();v!=graph[u].end();v++)
		if(!visited[*v])
			dfsUntil(graph,visited,*v,preu);
	closure[preu][u]=1;
}

void dfs(vector<vector<int> > &graph,int visited[],int vertex)
{
	for(int i=0;i<=vertex;i++)
	{
		{
		    dfsUntil(graph,visited,i,i);
	        //cout << i << endl;
		}
		for(int j=0;j<=vertex;j++)
		visited[j]=0;
	}
}

int main()
{
	int n,vertex;//number of lines
	scanf("%d %d",&n,&vertex);
	vector<vector<int> > graph(n+1);
	//Directed Acyclic graph
	int visited[vertex+1]={0};
	for(int i=0;i<=vertex;i++)
	{
	    for(int j=0;j<=vertex;j++)
	    closure[i][j]=0;
	}
	while(n--)
	{
		int u,v;//source destination
		scanf("%d %d",&u,&v);
		graph[u].push_back(v);
	}
    dfs(graph,visited,vertex);
    for(int i=0;i<=vertex;i++)
	{
	    for(int j=0;j<=vertex;j++)
	    cout << closure[i][j] << " ";
	    cout << endl;
	}
	return 0;
}
