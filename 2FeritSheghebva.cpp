#include<iostream>
#include <list>
using namespace std;
class Graph {
    int V;

    list<int>* adj;
public:
    Graph(int V);

    void addEdge(int v, int w);
    void BFS(int s);
};
Graph::Graph(int V) {
    this->V = V;
    adj = new list<int>[V];
}
//ვითვალისწინებთ რომ გრაფი არის არაორიენტირებული
void Graph::addEdge(int v, int w) {
    adj[v].push_back(w);
    adj[w].push_back(v);
}
//მოცემული ალგორითმი შეგვიძლია ჩავთვალოთ რომ მუშაობს
//იმ შემთხვევაშიც როცა არსებობს იზოლურებული წვერო(თუდნაც რამდენიმე)
//რადგან შეგვიძლია იგი შევღებოთ ნებისმიერ ფერად
void Graph::BFS(int s) {
    int* colors = new int[V];
    for (int i = 0; i < V; i++) {
        colors[i] = -1;
    }
    colors[s] = 1;
    list<int> queue;
    queue.push_back(s);
    list<int>::iterator i;
    while (!queue.empty()) {
        s = queue.front();
        queue.pop_front();
        for (i = adj[s].begin(); i != adj[s].end(); ++i) {
            if (colors[*i] == -1) {
                if (colors[s] == 1) {
                    colors[*i] = 0;
                    queue.push_back(*i);
                }
                else if (colors[s] == 0) {
                    colors[*i] = 1;
                    queue.push_back(*i);
                }
            }
            else if (colors[*i] == colors[s]) {
                cout << "ver shevghebavt ori ferit" << endl; return;
            }
        }
    }
    cout << "shevghebavt ori ferit " << endl;
}
int main() {
    //გვაქვს 6 წვერო თუმცა ერთერთი არის იზოლირებული
    //ამიტომაც იგი არ შევა მოსაზღვრე წვეროთა სიაში
    Graph G(6);
    G.addEdge(0, 2);
    G.addEdge(0, 3);
    G.addEdge(1, 2);
    G.addEdge(1, 3);
    G.addEdge(3, 4);
    G.BFS(0);
    return 0;
}