//floyed-warshall algorithm (all pair shortest path)

#include<bits/stdc++.h>
using namespace std;

void printGraph( int **arr, int V );

void floyedWarshell( int **graph, int V )
{
	int **arr = (int**)malloc(V*sizeof(int*));
	
	for( int i=0; i<V; i++ )
		arr[i] = (int*)malloc(V*sizeof(int));
	
	for( int i=0; i<V; i++ )
		for( int j=0; j<V; j++ )
			*(*(arr+i)+j) = *(*(graph+i)+j);
	
	
	for( int i=0; i<V; i++ )
	{
		for( int j=0; j<V; j++ )
		{
			for( int k=0; k<V; k++ )
			{
				if( *(*(arr+j)+k) > *(*(arr+j)+i) + *(*(arr+i)+k) )
					*(*(arr+j)+k) = *(*(arr+j)+i) + *(*(arr+i)+k);
			}
		}
	}
	
	printGraph(arr, V);
}

void printGraph( int **arr, int V )
{
	cout << "Shortest distances are: \n";
	for( int i=0; i<V; i++ )
	{
		for( int j=0; j<V; j++ )
			cout << *(*(arr+i)+j) << " ";
		cout << endl;
	}
}

int main()
{
	int vertex;
	
	cout << "Enter the number of vertices: ";
	cin >> vertex;
	
	int **graph = (int**)malloc(vertex*sizeof(int*));
	
	for( int i=0; i<vertex; i++ )
		graph[i] = (int*)malloc(vertex*sizeof(int));
	
	for( int i=0; i<vertex; i++ )
	{
		for( int j=0; j<vertex; j++ )
		{
			cout << "Enter the value of edge " << i << ", " << j << " : ";
			cin >> *(*(graph+i)+j);
		}
	}
	floyedWarshell(graph, vertex );
	
}