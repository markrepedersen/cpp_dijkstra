#include <functional>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<long long>
DijkstraSP(vector<vector<pair<long long, long long>>> &adjList,
           long long start) {
  vector<long long> dist(adjList.size(), -1);
  dist[start] = 0;
  priority_queue<pair<long long, long long>, vector<pair<long long, long long>>,
                 greater<pair<long long, long long>>>
      pq;

  pq.push(make_pair(start, 0));
  dist[start] = 0;

  while (pq.empty() == false) {
    long long u = pq.top().first;
    pq.pop();

    for (long long i = 0; i < adjList[u].size(); i++) {
      long long v = adjList[u][i].first;
      long long weight = adjList[u][i].second;

      if (dist[v] == -1 || dist[v] > dist[u] + weight) {
        dist[v] = dist[u] + weight;
        pq.push(make_pair(v, dist[v]));
      }
    }
  }

  return dist;
}

int main() {
  long long n, m, s;

  cin >> n >> m >> s;

  vector<vector<pair<long long, long long>>> graph(n);

  for (long long i = 0; i < m; ++i) {
    long long u, v, c;

    cin >> u >> v >> c;

    graph[u - 1].push_back(make_pair(v - 1, c));
    graph[v - 1].push_back(make_pair(u - 1, c));
  }

  vector<long long> distances = DijkstraSP(graph, s - 1);

  for (long long i : distances) {
    cout << i << " ";
  }
}
