#include<bits/stdc++.h>

using namespace std;

class Graph {
	public: 
		vector<list<int>> adj; // Adjacency List
		int v; // Total no of vertices

		Graph(int size) {
			v=size;
			adj.resize(v);
		}

		void Edge(int from, int to) {
			adj[from].push_back(to); 
		}	

		void DFS(int start) {
			vector<bool> visited; // List of visited nodes
			visited.resize(v, false); // Set all nodes as unvisited by default
			visited[start]=true; // Start node as visited

			list<int> stack;
			stack.push_front(start); // Push starting node
			while(!stack.empty()) {
				start=stack.front(); 
				cout<<start<<" ";
				stack.pop_front(); // Pop visited node
				for(auto it: adj[start]) {
					if(!visited[it]) { // Check if adjacent node is visited
						stack.push_front(it); // Push next node to stack if unvisited
						visited[it]=true; // Set Node as visited
					}
				}

			}

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
    g.DFS(2);
}