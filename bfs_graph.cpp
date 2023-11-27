#include<bits/stdc++.h>
using namespace std;

class Graph  {
	public:
		vector<list<int> > ADJ; // Adjacency List
		int V; // No of vertices
		
		Graph(int s) {
			V=s;
			ADJ.resize(V);
		}

		void Edge(int from, int to) {
			ADJ[from].push_back(to);
		}

		void BFS(int start) {
			vector<int> visited; // Maintain track of visited nodes
			visited.resize(V, false);  // Set all nodes as unvisited by default
			
			list<int> queue;
			visited[start]=true; // Mark first vertex as visited
			queue.push_back(start); // Push Starting Node

			while(!queue.empty()) {
				start=queue.front(); // Get first Element in queue
				cout<<start<< " ";
				queue.pop_front();
				
				for(auto it: ADJ[start]) {
					if(!visited[it]) {
						visited[it]=true; // Mark Vertex as visited
						queue.push_back(it); // Add vertex to queue
					}
				}

			}
			cout<<endl;
		}
};

int main() {
    Graph g(4);
    g.Edge(0, 1);
    g.Edge(0, 2);
    g.Edge(1, 2);
    g.Edge(2, 0);
    g.Edge(2, 3);
    g.Edge(3, 3);
    g.BFS(2);
}
