#include <iostream>
#include <queue>
#include <functional>
#include <list>
using namespace std;
//INF-usasruloba
# define INF 0x3f3f3f3f 
typedef pair<int, int> iPair;
class Graph
{
	int V; // cveroebis raod.
	list< pair<int, int> >* adj;
	void printPath(vector<int>parent, int j) {
		if (parent[j] == -1)
			return;
		printPath(parent, parent[j]);
		cout << j << ' ';
	}
public:
	Graph(int V); // constructori grafistvis cibos dasamateblad 
	void addEdge(int u, int v, int w);
	// s sackisi cverodan umoklesi gzebi
	void shortestPath(int s);
	void printInfo(int s, vector<int> dist, int V, vector<int> parent);
};
// Allocates memory for adjacency list 
Graph::Graph(int V)
{
	this->V = V;
	adj = new list<iPair>[V];
}
void Graph::addEdge(int u, int v, int w)
{
	adj[u].push_back(make_pair(v, w));
	//adj[v].push_back(make_pair(u, w));
}
// dabechdavs umokles gzas src-dan kvela danarchen cveromde 
void Graph::shortestPath(int s)
{
	// Create a priority queue to store vertices that // are being preprocessed. 
	priority_queue< iPair, vector <iPair>, greater<iPair> > pq;
	// inicializacia: kvela cverostvis mandzili gaxdes INF
	vector<int> dist(V, INF);
	vector<int> parent(V);
	for (int i = 0; i < V; i++) {
		parent[i] = i;
	}

	// ShevikvanoT sackisi cvero prior.rigshi(pq) 
	// sackisi cverostvis(src)mandzili gaxdes 0. 
	pq.push(make_pair(0, s));
	dist[s] = 0;
	parent[s] = -1;
	while (!pq.empty())
	{
		// pirveli elementi ckvilshi aris minimaluri mandzili, meore-cvero. 
		//gachumebis principit prioriteti ganisazgvreba pirveli elementit.
		int u = pq.top().second;
		pq.pop();
		// 'i' iteratori
		list< pair<int, int> >::iterator i;
		for (i = adj[u].begin(); i != adj[u].end(); ++i)
		{
			// Get vertex label and weight of current adjacent 
			// u cveros mimdinare sheugl.cvero v da (u,v) cibos cona. 
			int v = (*i).first;
			int weight = (*i).second;
			// relaxation 
			if (dist[v] > dist[u] + weight)
			{
				dist[v] = dist[u] + weight;
				parent[v] = u;
				pq.push(make_pair(dist[v], v));
			}
		}
	}
	// dabechde umoklesi gzebi, romelic inaxeba dist[] 
	//printf("Vertex Distance from Source\n");
	printInfo(s,dist, V, parent);
}
void Graph::printInfo(int s,vector<int> dist, int V, vector<int> parent) {
	cout << "Source is " << s << endl;
	for (int i = 0; i < V; i++) {
		if (dist[i] != INF) {
			cout << "Distance from " << s << " To " << i << " = " << dist[i] << ", Path : " << s << ' ';
			printPath(parent, i);
			cout << endl;
		}
	}
}
int main()
{
	int V = 9;
	Graph g(V);
	g.addEdge(0, 1, 4);
	g.addEdge(0, 7, 8);
	g.addEdge(1, 2, 8);
	g.addEdge(1, 7, 11); g.addEdge(2, 3, 7);
	g.addEdge(2, 8, 2);
	g.addEdge(2, 5, 4);
	g.addEdge(3, 4, 9);
	g.addEdge(3, 5, 14);
	g.addEdge(4, 5, 10);
	g.addEdge(5, 6, 2);
	g.addEdge(6, 7, 1);
	g.addEdge(6, 8, 6);
	g.addEdge(7, 8, 7);
	g.shortestPath(0);
	return 0;
}
