//dijkstra algo

#include<bits/stdc++.h>
#define MAX 100
using namespace std;

void swap( int *x, int *y )
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

class minPriorityQueue
{
	pair <int, int> arr[MAX];
	int size;
	
	public:
		minPriorityQueue()
		{
			size = 0;
		}
		
		bool isEmpty()
		{
			if( size == 0 )
				return true;
			return false;
		}
		
		int isPresent( int x )
		{
			for( int i=1; i<=size; i++ )
				if( x == arr[i].first )
					return i;
			return 0;
		}
		
		int getMin()
		{
			return arr[1].first;
		}
		
		int getKey( int x )
		{
			for( int i=1; i<=size; i++ )
				if( x == arr[i].first )
					return arr[i].second;
			return -1;
		}
		
		void insert( int key, int value )
		{
			size++;
			arr[size].first = key;
			arr[size].second = INT_MAX;
			
			decreaseKey( key, value );
		}
		
		void decreaseKey(int key, int value)
		{
			int index = isPresent(key);
			arr[index].second = value;
			
			int parent = index/2;
			while( parent > 0 && arr[parent].second > arr[index].second )
			{
				swap( &arr[parent].first, &arr[index].first );
				swap( &arr[parent].second, &arr[index].second );
				
				index = parent;
				parent = parent/2;
			}
		}
		
		void minHeapify( int index )
		{
			int left = 2*index;
			int right = 2*index + 1;
			
			int smallest;
			if( left <= size && arr[left].second < arr[index].second )
				smallest = left;
			else
				smallest = index;
				
			if( right <= size && arr[right].second < arr[smallest].second )
				smallest = right;
				
			if( index != smallest )
			{
				swap( &arr[index].first, &arr[smallest].first );
				swap( &arr[index].second, &arr[smallest].second );
				
				minHeapify(smallest);	
			} 
		}
		
		int extractMin( int *x )
		{
			int min = arr[1].first;
			*x = arr[1].second;
			
			arr[1].first = arr[size].first;
			arr[1].second = arr[size].second;
			
			size--;
			
			minHeapify(1);
			
			return min;
		}
};

class Graph
{
	int V;
	vector < pair<int, int> > *adj;
	
	public:
		Graph(int V)
		{
			this->V = V;
			this->adj = new vector < pair<int, int> >[V];
		}
		
		void addEdge( int u, int v, int w )
		{
			adj[u].push_back( make_pair( v, w) );
			adj[v].push_back( make_pair( u, w) );
		}
		
		void dijkstra( int src )
		{
			int d[V];
			
			minPriorityQueue q;
			Graph g(V);
			
			for( int i=0; i<V; i++ )
				q.insert(i, INT_MAX);
				
			for( int i=0; i<V; i++ )
				d[i] = 0;
			
			q.decreaseKey(src, 0);
			
			while( !q.isEmpty() )
			{
				int x;
				int u = q.getMin();
				int temp = q.getKey(u); 
				u = q.extractMin(&x);
			
				vector <pair<int, int> >:: iterator itr;
				for( itr= adj[u].begin(); itr != adj[u].end(); itr++ )
				{
					if( q.isPresent((*itr).first)  && temp + (*itr).second < q.getKey((*itr).first) )
					{
						d[(*itr).first] = temp + (*itr).second;
						q.decreaseKey((*itr).first, temp + (*itr).second );
					}
				}
			}
			
			cout << "Distance of all vertices from " << src << " are: \n";
			for( int i=0; i<V; i++ )
				cout << "( " << i << " : " << d[i] << " ), ";
			cout << endl;
		}
		
		void display()
		{
			vector < pair<int, int> >:: iterator itr;
			for( int i=0; i<V; i++ )
			{
				cout << i << "  ";
				for( itr = adj[i].begin(); itr != adj[i].end(); itr++ )
				{
					cout << "( " << (*itr).first << ", " << (*itr).second << " )" << "  "; 
				}
				cout << endl;
			}
		}
};

int main()
{
	int vertex, u, v, w, choice;

	cout << "Enter number of vertices: ";
	cin >> vertex;
	
	Graph g(vertex);
	
	cout << "Do you want to enter edges? (1.Yes 2.No) : ";
	cin >> choice;
	
	while( choice != 2 )
	{
		if( choice != 1 )
		{
			cout << "Wrong entry!!\n";
			cout << "Do you want to enter edges? (1.Yes 2.No) : ";
			cin >> choice;
			continue;
		}
		cout << "Enter edge( with weight ): ";
		cin >> u >> v >> w;
		
		g.addEdge(u, v, w);
		
		cout << "Do you want to enter edges? (1.Yes 2.No) : ";
		cin >> choice;
	}
	g.dijkstra(0);
}






