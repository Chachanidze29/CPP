#include <iostream>
#include <list>
using namespace std;
class Graph {
	int V;
	list<int>* adj;
public:
	Graph(int V) {
		this->V = V;
		adj = new list<int>[V];
	}
	void addEdge(int v,int w);
	Graph Transpose();
	void dfsviz(int v,bool visited[]);
	bool isStronglyConnected();
};
void Graph::addEdge(int v, int w) {
	adj[v].push_back(w);
}
Graph Graph::Transpose() {
	Graph g(V);
	for (int v = 0; v < V; v++) {
		list<int>::iterator i;
		for (i = adj[v].begin(); i != adj[v].end(); i++) {
			g.adj[*i].push_back(v);
		}
	}
	return g;
}
void Graph::dfsviz(int v, bool visited[]) {
	visited[v] = true;
	list<int>::iterator i;
	for (i = adj[v].begin(); i != adj[v].end(); i++) {
		if (!visited[*i])
			dfsviz(*i, visited);
	}
}
bool Graph::isStronglyConnected() {
	bool* visited = new bool[V];
	for (int i = 0; i < V; i++) {
		visited[i] = false;
	}
	dfsviz(0, visited);
	for (int i = 0; i < V; i++) {
		if (visited[i] == false)
			return false;
	}
	Graph T = Transpose();
	for (int i = 0; i < V; i++) {
		visited[i] = false;
	}
	T.dfsviz(0, visited);
	for (int i = 0; i < V; i++) {
		if (visited[i] == false)
			return false;
	}
	return true;
}
int main() {
	Graph g(5);
	g.addEdge(0, 1);
	g.addEdge(3, 0);
	g.addEdge(1, 3);
	g.addEdge(4, 1);
	g.addEdge(2, 4);
	g.isStronglyConnected() ? cout << "Is strongly connected\n" : cout << "Isn't strongly connected\n";
}