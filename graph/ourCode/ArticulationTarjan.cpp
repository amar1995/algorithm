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

void ApUtil(int u,vector<vector<int>  > &graph,int visited[],int parent[],bool ap[],int disc[],int low[])
{
	static int time=0;
	int children=0;
	visited[u]=1;
	time+=1;
	disc[u]=time;
	low[u]=time;
	for(vector<int>::iterator v=graph[u].begin();v!=graph[u].end();v++)
	{
	    int i=*v;
		if(!visited[*v])
		{
			children++;
            parent[i] = u;
            ApUtil(i,graph, visited, parent,  ap ,disc, low);
            low[u]  = min(low[u], low[i]);
            if (parent[u] == -1 && children > 1)
               ap[u] = true;
            if (parent[u] != -1 && low[i] >= disc[u])
               ap[u] = true;
		}
		else if(parent[u]!=i)
		{
			low[u]=min(low[u],disc[i]);
		}
	}
}

void ArticulationPoint(vector<vector<int > > &graph,int vertex)
{
	int i;
	int parent[vertex+1];
	memset(parent,-1,sizeof(parent));
	bool ap[vertex+1];
	memset(ap,false,sizeof(ap));
	int disc[vertex+1];
	int low[vertex+1];
	int visited[vertex+1]={0};
	for(i=0;i<=vertex;i++)
	{
		if(!visited[i])
			ApUtil(i,graph,visited,parent,ap,disc,low);
	}
	for(i=0;i<=vertex;i++)
	{
		if(ap[i])
			printf("%d ",i);
	}
}

int main(void)
{
	int n,vertex,u,v,weight;
	scanf("%d %d",&n,&vertex);
	vector<vector<int> > graph(vertex+1);
	while(n--)
	{
		scanf("%d %d",&u,&v);
		graph[u].push_back(v);
		graph[v].push_back(u);		
	}
	
    ArticulationPoint(graph,vertex);
	return 0;
}

//Related Topic Biconnected graph
// and Bridge Graph
//http://www.geeksforgeeks.org/biconnectivity-in-a-graph/
//http://www.geeksforgeeks.org/bridge-in-a-graph/