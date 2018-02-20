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

void topoSortUntil(vector<vector<int> > &graph,int visited[],stack<int> &s,int u)
{
    visited[u]=1;
    for(vector<int>::iterator v = graph[u].begin();v!=graph[u].end();v++)
    {
        if(!visited[*v])
        {
            topoSortUntil(graph,visited,s,*v);
        }
    }
    s.push(u);
}

void topologicalSort(vector<vector<int>  > &graph,int visited[],int vertex)
{
	stack<int> s;
	for(int i=1;i<=vertex;i++)
	{
	    if(!visited[i])
	    {
	        topoSortUntil(graph,visited,s,i);
	    }
	}
	while(!s.empty())
	{
		cout << s.top() << " ";
		s.pop();
	}
}

int main()
{
	int n,vertex;//number of lines
	scanf("%d %d",&n,&vertex);
	//directed acyclic graph 
	vector<vector<int> > graph(vertex+1);
	int visited[vertex+1]={0};
	while(n--)
	{
		int u,v;//source destination
		scanf("%d %d",&u,&v);
		graph[u].push_back(v);
	}
	topologicalSort(graph,visited,vertex);
	return 0;
}
