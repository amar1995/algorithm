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

void bfs(vector<vector<int> > &graph,int visited[])
{
	queue<int> q;
	q.push(1);
	visited[1]=1;
	while(!q.empty())
	{
		int u = q.front();
		q.pop();
		for(vector<int>::iterator v = graph[u].begin();v!=graph[u].end();v++)
		{
			if(!visited[*v])
			{
				q.push(*v);
				visited[*v]=1;
			}
		}
		cout << u << " ";
	}
}

int main()
{
	int n;//number of lines
	scanf("%d",&n);
	vector<vector<int> > graph(n+1);
	int visited[n+1]={0};
	while(n--)
	{
		int u,v;//source destination
		scanf("%d %d",&u,&v);
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	bfs(graph,visited);
	return 0;
}
