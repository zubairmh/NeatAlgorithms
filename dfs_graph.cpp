#include<bits/stdc++.h>

using namespace std;

class Graph {
	public: 
		vector<list<int>> adj;
		int v;

		Graph(int size) {
			v=size;
			adj.resize(v);
		}

		void Edge(int from, int to) {
			adj[from].push_back(to);
		}	

		void DFS(int start) {
			vector<bool> visited;
			visited.resize(v, false);
			visited[start]=true;

			list<int> stack;
			stack.push_front(start);
			while(!stack.empty()) {
				start=stack.front();
				cout<<start<<" ";
				stack.pop_front();
				for(auto it: adj[start]) {
					if(!visited[it]) {
						stack.push_front(it);
						visited[it]=true;
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