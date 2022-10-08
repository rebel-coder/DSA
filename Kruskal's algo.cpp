//kruskal's algorithm

#include<bits/stdc++.h>
using namespace std;

typedef struct edge
{
	int src, dest, w;
};

class Graph
{
	int V, E;
	edge *Edge;
	int count;
	
	public:
		Graph( int V, int E )
		{
			this->V = V;
			this->E = E;
			this->Edge = new edge[E];
			count = 0;
		}
		
		void addEdge( int src, int dest, int w )
		{
			Edge[count].src = src;
			Edge[count].dest = dest;
			Edge[count].w = w;
			count++;
		}
		
		static int compare( const void *x, const void *y )
		{
			edge* e1 = (edge*)x;
			edge* e2 = (edge*)y;
			if( e1->w < e2->w )
				return -1;
			else if( e1->w > e2->w )
				return 1;
			return 0;
		}
		
		int find( int *parent, int x )
		{
			if( parent[x] == -1 )
				return x;
			return find( parent, parent[x] );
		}
		
		void Union( int *parent, int x, int y )
		{
			int a = find( parent, x );
			int b = find( parent, y );
			
			if( a != b )
				parent[a] = b;
		}
		
		void KruskalMST()
		{
			Graph g(V, E);
			int parent[V];
			
			qsort( Edge, E, sizeof(edge), compare );
			
			for( int i=0; i<V; i++ )
				parent[i] = -1;
			
			int i, count;
			i = 0;
			count = 0;
			while( count < V-1 && i < E )
			{
				edge e = Edge[i++];
				
				int x = find( parent, e.src );
				int y = find( parent, e.dest );
				
				if( x != y )
				{
					g.addEdge(e.src, e.dest, e.w );
					Union( parent, e.src, e.dest );
					count++;
				}
			}
			g.display();
		}		
		
		void display()
		{
			cout << "Edges of MST are:\n";
			for( int i=0; i<E; i++ )
				cout << "( " << Edge[i].src << ", " << Edge[i].dest << " ),  w = " << Edge[i].w << "    "; 
		}
};

int main()
{
	int vertex, edge, u, v, w;
	
	cout << "Enter the number of vertex: ";
	cin >> vertex;
	
	cout << "Enter the number of edges: ";
	cin >> edge;
	Graph g(vertex, edge);
	
	cout << "Enter the edges (with weights): \n";
	for( int i=0; i<edge; i++ )
	{
		cin >> u >> v >> w;
		g.addEdge( u, v, w );
	}
	
	g.KruskalMST();
}




