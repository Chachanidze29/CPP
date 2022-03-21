#include<iostream>
#include <list>
using namespace std;
//a b c d f
//0 1 2 3 4
class Graph
{
	int V;

	list<int>* adj; 
public:
	Graph(int V);
	void addEdge(int v, int w); 
	void printG();
};
Graph::Graph(int V)
{
	this->V = V;
	adj = new list<int>[V];
}
void Graph::addEdge(int v, int w)
{
	adj[v].push_back(w); 
}
void Graph::printG() {
	for (int i = 0; i < V; i++) {
		cout << i << " -> ";
		for (auto it = adj[i].begin(); it != adj[i].end(); it++)
			cout << *it << " ";
		cout << endl;
	}
}
int main()
{
	Graph g(5);
	g.addEdge(0, 3);
	g.addEdge(1, 0);
	g.addEdge(1, 4);
	g.addEdge(2, 1);
	g.addEdge(2, 2);
	g.addEdge(3, 1);
	g.addEdge(4, 2);
	cout << "representation of graph using adjacency list representation" << endl;
	g.printG();
	return 0;
}
