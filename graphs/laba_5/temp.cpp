#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <stack>
#include <algorithm>

using namespace std;

const int INF = numeric_limits<int>::max();

struct Edge {
    int to;
    int weight;
};

void dijkstra(int n, int start, const vector<vector<Edge>>& adj, vector<int>& dist, vector<int>& parent) {
    dist.assign(n, INF);
    parent.assign(n, -1);
    dist[start] = 0;

    using pii = pair<int, int>; // (distance, vertex)
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.emplace(0, start);

    while (!pq.empty()) {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (d > dist[u]) continue;

        for (const Edge& edge : adj[u]) {
            int v = edge.to;
            int w = edge.weight;
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                parent[v] = u;
                pq.emplace(dist[v], v);
            }
        }
    }
}

vector<int> restore_path(int target, const vector<int>& parent) {
    vector<int> path;
    for (int v = target; v != -1; v = parent[v]) {
        path.push_back(v);
    }
    reverse(path.begin(), path.end());
    return path;
}

int main() {
    int n, m, start;
    cin >> n >> m >> start;
    vector<vector<Edge>> adj(n);

    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }

    vector<int> dist, parent;
    dijkstra(n, start, adj, dist, parent);

    cout << "Distances from vertex " << static_cast<char>(start + 'a') << ":\n";
    for (int i = 0; i < n; ++i) {
        std::cout << static_cast<char>(start + 'a') << "-" << static_cast<char>(i + 'a') << "(";
        if (dist[i] == INF) cout << "unreachable";
        else cout << dist[i];
        std::cout << "): ";
        if (dist[i] == INF) {
            std::cout << "\n";
            continue;
        }
        vector<int> path = restore_path(i, parent);
        for (int v : path) cout << static_cast<char>(v + 'a') << " ";
        cout << "\n";
    }

    cout << "\nPaths from vertex " << static_cast<char>(start + 'a') << ":\n";
    for (int i = 0; i < n; ++i) {
    }

    return 0;
}

