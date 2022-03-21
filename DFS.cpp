#include<iostream>
#include<list>
using namespace std;
class Graph {
	int V;
	list<int>* adj;
public:
	Graph(int V);
	void addEdge(int x, int y);
	void dfsviz(int v, bool* visited);
	void DFS(int v);
};
Graph::Graph(int V)
{
	this->V = V;
	adj = new list<int>[V];
}
void Graph::addEdge(int x, int y)
{
	adj[x].push_back(y);
}
void Graph::dfsviz(int v, bool* visited)
{
	visited[v] = true;
	cout << v << " ";
	for (auto i = adj[v].begin(); i != adj[v].end(); i++)
		if (!visited[*i]) {
			visited[*i] = true;
			dfsviz(*i, visited);
		}
}
void Graph::DFS(int v) {
	bool* visited = new bool[V];
	for (int i = 0; i < V; i++)
		visited[i] = false;
	dfsviz(v, visited); cout << endl;
	for (int i = 0; i < V; i++) {
		if (!visited[i]) {
			dfsviz(i, visited);
			cout << endl;
		}
	}
}
int main() {
	Graph g(6);
	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(0, 4); 
	g.addEdge(1, 3); 
	g.addEdge(4, 5);
	g.addEdge(1, 0); 
	g.addEdge(2, 0);
	g.addEdge(4, 0);
	g.addEdge(5, 4); 
	g.addEdge(3, 1);
	g.DFS(0);
}
