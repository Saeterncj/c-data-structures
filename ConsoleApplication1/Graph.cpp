/******************************************************************************
*
* @file     graph.cpp
* @brief    Intro to Graph data Structures
* @version  V1.00
* @date     9, December 2018
*
* @note
*
******************************************************************************/

/*----------------------------------------------------------------------------
*
* Place #include files required to compile this source file here.
*
*----------------------------------------------------------------------------*/
#include "Graph.h"

/*----------------------------------------------------------------------------
*
* Place function prototypes that will be used only by this file here.
* This section need only include "forward referenced" functions.
*
*----------------------------------------------------------------------------*/


/*----------------------------------------------------------------------------
*
* Define global variables that will be used by both this source file
* and by other source files here.
*
*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------
*
* Place #define constants and macros that will be used only by this
* source file here.
*
*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------
*
* Place typedefs, structs, unions, and enums that will be used only
* by this source file here.
*
*----------------------------------------------------------------------------*/
struct Graph {
	int V; // vertices
	//set<int, greater<int>> * adjlist;	//Using Sets
	unordered_set<int> *adjlist;	//Uses cheap Hash
	Graph(int V) {
		this->V = V;
		this->adjlist = new unordered_set<int>[V];
	}
	void addEdges(int v1, int v2) {
		this->adjlist[v1].insert(v2);
		this->adjlist[v2].insert(v1);
	}
	void printGraph() {
		for (int i(0); i < this->V; i++) {
			cout << "The adjacency list of: " << i << "\n";
			cout << " head";
			for (auto v2 : this->adjlist[i]) {
				cout << " << " << v2;
			}
			cout << "\n";
		}
	}
	bool isCyclicUtil(int v, bool visited[], int parent) {
		// Mark the current node as visited 
		visited[v] = true;
		// Recur for all the vertices adjacent to this vertex 
		for (auto it : adjlist[v]) {
			// If an adjacent is not visited, then recur for that adjacent 
			if (!visited[it]) {
				if (isCyclicUtil(it, visited, v))
					return true;
			}
			// If an adjacent is visited and not parent of current vertex, 
			// then there is a cycle. 
			else if (it != parent)
				return true;
		}
		return false;
 	}

	bool isCyclic() {
		bool *visited = new bool[V];
		for (int i(0); i < V; i++)
			visited[i] = false;

		if (isCyclicUtil(0, visited, -1))
			return true;
		return false;
	}
};
/*----------------------------------------------------------------------------
*
* Place static variables that will be used only by this file here.
*
*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------
*
* Place function bodies here.
*
*----------------------------------------------------------------------------*/
/*
Graph* createGraph(int V) {
	Graph* graph = new Graph;
	graph->V = V;
	//graph->adjlist = new set<int, greater<int> >[V];
	graph->adjlist = new unordered_set<int>[V];	// using cheap Hash
	return graph;
}
void addEdges(Graph *graph, int v1, int v2) {
	graph->adjlist[v1].insert(v2);
	graph->adjlist[v2].insert(v1);
}
void printGraph(Graph * graph) {
	for (int i(0); i < graph->V; i++) {
		cout << "The adjacency list of: " << i << "\n";
		cout << " head";
		for (auto v2 : graph->adjlist[i]) {
			cout << " << " << v2;
		}
		cout << "\n";
	}
}
*/
// The following ARe undirected graph. DFS and BFS implemented
void addEdges(vector<int> arr[], int v1, int v2) {
	arr[v1].push_back(v2);
	arr[v2].push_back(v1);
}
void printGraph(vector<int> arr[], int V) {
	for (int i(0); i < V; i++) {
		cout << "The adjacency list of: " << i << "\n";
		cout << " head";
		for (auto v2 : arr[i]) {
			cout << " << " << v2;
		}
		cout << "\n";
	}
}
// Breadth first search
void BFS(vector<int> arr[], int V,int v2) {
	bool *visited =  new bool[V];
	// vector<bool> visited (V,false);
	for (int i(0); i < V; i++)
		visited[i] = false;
	queue<int> myQ;
	myQ.push(v2);
	visited[v2] = true;
	while (!myQ.empty()) {
		int front = myQ.front();
		myQ.pop();
		cout << front << " ";
		for (auto vertices : arr[front]) {
			if (!visited[vertices]) {
				myQ.push(vertices);
				visited[vertices] = true;
			}
		}
	}
	delete[] visited;
}
void DFSutil(vector<int> arr[], bool visited[],int i ) {
	visited[i] = true;
	cout << i << " ";
	for (auto it : arr[i]) {
		if (!visited[it])
			DFSutil(arr, visited, it);
	}
}
void DFS(vector<int> arr[],int V) {
	bool *visited = new bool[V];
	for (int i(0); i < V; i++) {
		visited[i] = false;
	}
	DFSutil(arr, visited, 5);
}
void graphLoop() {
	const int V = 7;
	//vector<int> adj[V];
	/*
	Graph *adj = createGraph(V);
	addEdges(adj, 0, 1);
	addEdges(adj, 0, 4);
	addEdges(adj, 1, 2);
	addEdges(adj, 1, 3);
	addEdges(adj, 1, 4);
	addEdges(adj, 2, 3);
	addEdges(adj, 3, 4);
	addEdges(adj, 4, 5);
	addEdges(adj, 4, 6);*/
	//printGraph(adj, V);
	Graph G(V);
	G.addEdges(0, 1);
	G.addEdges( 0, 4);
	G.addEdges( 1, 2);
	//G.addEdges( 1, 3);
	//G.addEdges( 1, 4);
	G.addEdges( 2, 3);
	//G.addEdges( 3, 4);
	G.addEdges( 4, 5);
	G.addEdges( 4, 6);
	G.addEdges(5, 6);
	G.printGraph();
	G.isCyclic() ? cout << "Graph contains Cycle\n" : cout << "Graph doesn't contain Cycle\n";
	//BFS(adj, V, 0);
	cout << endl;
	//DFS(adj, V);
}