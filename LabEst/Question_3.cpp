#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<pair<int, int>>> graph(n + 1);

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back(make_pair(v, w));
    }

    const int INF = 1000000000;
    vector<int> dist(n + 1, INF);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    dist[k] = 0;
    pq.push(make_pair(0, k));

    while (!pq.empty()) {
        pair<int, int> current = pq.top();
        pq.pop();

        int d = current.first;
        int node = current.second;

        if (d != dist[node]) {
            continue;
        }

        for (int i = 0; i < (int)graph[node].size(); i++) {
            int nextNode = graph[node][i].first;
            int weight = graph[node][i].second;

            if (dist[nextNode] > d + weight) {
                dist[nextNode] = d + weight;
                pq.push(make_pair(dist[nextNode], nextNode));
            }
        }
    }

    int answer = 0;
    for (int i = 1; i <= n; i++) {
        if (dist[i] == INF) {
            cout << -1;
            return 0;
        }
        if (dist[i] > answer) {
            answer = dist[i];
        }
    }

    cout << answer;
    return 0;
}
