#include <bits/stdc++.h>
using namespace std;

const int N = 1000; 
vector<pair<int, int>> g[N];

void dijkstra(int source) {
    vector<int> dist(N, INT_MAX); // Initialize distances to a very large value
    vector<bool> vis(N, false);  // Visited array to keep track of processed nodes
    set<pair<int, int>> st;      // {distance, vertex}

    st.insert({0, source});
    dist[source] = 0;

    while (!st.empty()) {
        auto node = *st.begin();
        st.erase(st.begin());

        int v = node.second;
        int curr_dist = node.first;

        if (vis[v]) continue; // Skip if already visited
        vis[v] = true;

        for (auto child : g[v]) {
            int child_v = child.first;
            int wt = child.second;
            if (dist[v] + wt < dist[child_v]) {
                dist[child_v] = dist[v] + wt;
                st.insert({dist[child_v], child_v});
            }
        }
        
            
        
    }

    for (int i = 0; i < N; i++) {
        if (!g[i].empty()) {
            cout << "Node " << i << ": ";
            for (auto edge : g[i]) {
                cout << "(" << edge.first << ", " << edge.second << ") ";
            }
        cout << endl;
        }
    }
 }


int main() {
    int edges;
    cout << "Enter the number of edges: ";
    cin >> edges;

    for (int i = 0; i < edges; i++) {
        int u, v, w;
        cout << "Enter edge (u v w): ";
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w}); // Omit this line for a directed graph
    }

    int source;
    cout << "Enter source node: ";
    cin >> source;

    dijkstra(source);
    return 0;
}
