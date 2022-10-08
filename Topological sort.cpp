//Topological sort

#include<iostream>
#include<stack>
#include<list>
using namespace std;

typedef struct graph
{
	int vertex;
	list<int> *adj;
};

graph createGraph();
void topologicalSort(graph g);
void topologicalSortUtil( graph g, int u, bool *visited, stack<int>s );

int main()
{
	graph G;
	G = createGraph();	
	
	//Topological sort
	topologicalSort(G);
}

void topologicalSort(graph g)
{
	bool visited[g.vertex+1] = {false};
	stack<int>s;
	
	for(int i=1; i<=g.vertex; i++)
	{
		if( visited[i] == false )
			topologicalSortUtil(g, i, visited, s);
	}
	
	while( !s.empty() )
	{
		cout << s.top() << " ";
		s.pop();
	}
}

void topologicalSortUtil( graph g, int u, bool *visited, stack<int>&s )
{
	visited[u] = true;
	
	list<int>:: iterator j;
	for( j = g.adj[u].begin(); j != g.adj[u].end(); j++ )
	{
		if( visited[*j] == false )
			topologicalSortUtil(g, *j, visited, *s);
	}
	(s).push(u);
}

graph createGraph()
{
	graph g;
	int choice, u, v;
	
	cout << "Enter the number of vertices:  ";
	cin >> g.vertex;
	
	g.adj = new list<int>[g.vertex+1];
	
	cout << "Do you want to enter the edge? (1.Yes 2.No) : ";
	cin >> choice;
	
	while( choice == 1 )
	{
		cout << "Enter the edge: ";
		cin >> u >> v;
		
		g.adj[u].push_back(v);
		g.adj[v].push_back(u);
		
		cout << "Do you want to enter the edge? (1.Yes 2.No) : ";
		cin >> choice;
	}
	return g;
}