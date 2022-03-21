#include <iostream>
#include <queue>
#include <functional>
#include <list>
using namespace std;
# define INF 0x3f3f3f3f 
typedef pair<int, int> iPair;
class Graph
{
	int V; 
	list< pair<int, int> >* adj;
	void printPath(vector<int>parent, int j) {
		if (parent[j] == -1)
			return;
		printPath(parent, parent[j]);
		cout << j << ' ';
	}
public:
	Graph(int V);
	void addEdge(int u, int v, int w);
	void shortestPath(int,int);
	void printInfo(int ,int, vector<int> dist, vector<int>, vector<int>);
}; 
Graph::Graph(int V)
{
	this->V = V;
	adj = new list<iPair>[V];
}
void Graph::addEdge(int u, int v, int w)
{
	adj[u].push_back(make_pair(v, w));
}
void Graph::shortestPath(int s1,int s2) //იღებს ორ პარამეტრს. პირველი საიდანაც გვინდა ვიპოვოთ უმოკლესი გზები,მეორე წვერო რომლის გავლითაც გვინდა ვიპოვნოთ უმოკლესი გზები
{
	//Source წვერო ხდება პირველი ანუ ის წვერო საიდანაც გვინდა ვიპოვნოთ უმოკლესი გზები
	int s = s1;
	//ვატარებთ დეიქსტრას ალგორითმს s1 წვეროდან s2 წვეროსთვის
	priority_queue< iPair, vector <iPair>, greater<iPair> > pq;
	vector<int> dist(V, INF);
	vector<int> parent(V);
	for (int i = 0; i < V; i++) {
		parent[i] = i;
	} 
	pq.push(make_pair(0, s));
	dist[s] = 0;
	parent[s] = -1;
	while (!pq.empty())
	{
		int u = pq.top().second;
		pq.pop();
		list< pair<int, int> >::iterator i;
		for (i = adj[u].begin(); i != adj[u].end(); ++i)
		{
			int v = (*i).first;
			int weight = (*i).second;
			if (dist[v] > dist[u] + weight)
			{
				if (v == s2) { // ვინახავ მანძილს და გზას s1იდან s2-მდე
					dist[v] = dist[u] + weight;
					parent[v] = u;
					pq.push(make_pair(dist[v], v));
				}
			}
		}
	}
	//ვინახავ მანძილს s1-დან s2-მდე num ცვლადში
	int num = 0;
	for (int i = 0; i < V; i++) {
		if (dist[i] != INF && dist[i] != 0) {
			num += dist[i];
		}
	}
	//source წვერო ხდება მეორე წვერო და ამ წვეროსთვის ვპოულობ უმოკლეს მანძილს ყველა წვეროსთვის გარდა s1-ისა.
	s = s2;
	//ვქმნი ახლი queue ს და vector-ებს
	priority_queue< iPair, vector <iPair>, greater<iPair> > pq1;
	vector<int> dist1(V, INF);
	vector<int> parent1(V);
	for (int i = 0; i < V; i++) {
		parent1[i] = i;
	}
	pq1.push(make_pair(0, s));
	dist1[s] = 0;
	parent1[s] = -1;
	while (!pq1.empty())
	{
		int u = pq1.top().second;
		pq1.pop();
		list< pair<int, int> >::iterator i;
		for (i = adj[u].begin(); i != adj[u].end(); ++i)
		{ 
			int v = (*i).first;
			int weight = (*i).second;
			if (v == s1) { continue; } //ვპოულობ უმოკლეს მანძილს s2-იდან ყველა წვერომდე გარდა s1-ისა
			if (dist1[v] > dist1[u] + weight)
			{
					dist1[v] = dist1[u] + weight;
					parent1[v] = u;
					pq1.push(make_pair(dist1[v], v));
			}
		}
	}
	//ამ მანძილებს ვზრდი შენახული num ცვლადით რადგან s1-და s2-მდე მანძილი ამ num ცვლადშია შენახული
	for (int i = 0; i < V; i++) {
		if (dist1[i] != INF)
			dist1[i] += num;
	}
	printInfo(s1, s2, dist1, parent1, parent);
}
//ბეჭდვის ფუნქცია იღებს იმ წვეროს საიდანაც გვინდა ვიპოვნოთ უმოკლესი მანძილი და იმ წვეროს რომლის გავლითაც გვინდა ეს
//ასევე იღებს მანძილების ვექტორს და 2 parent ვექტორს.ერთს იმისთვის რომ დავბეჭდოთ გზა s1-s2 მდე ხოლო მეორეს იმისთვის რომ
//დავბეჭდოთ გზა s2დან დანარჩენებამდე
void Graph::printInfo(int s1,int s2, vector<int> dist, vector<int> parent1, vector<int> parent) {
	cout << "Source is " << s1 << endl; 
	for (int i = 0; i < V; i++) {
		if (dist[i] != INF) {
			cout << "Distance from source " << s1 << " To " << i << " = " << dist[i] << ", Path : ";
			printPath(parent, s2); //ვბეჭდავ გზას s1-დან s2 მდე
			printPath(parent1, i); //ვბეჭდავ გზას s2-იდან სხვებამდე
			//ანუ გამოდის რომ ვბეჭდავ გზას s1-დან ყველა წვერომდე s2-ის გავლით.
		}
		cout << endl;
	}
}
int main()
{
	int V = 5;
	Graph g(V);
	g.addEdge(0, 1, 9);
	g.addEdge(0, 3, 6);
	g.addEdge(1, 2, 8);
	g.addEdge(1, 4, 3);
	g.addEdge(3, 1, 2);
	g.addEdge(4, 2, 4);
	g.addEdge(4, 3, 1);
	g.shortestPath(0, 1);
	return 0;
}	