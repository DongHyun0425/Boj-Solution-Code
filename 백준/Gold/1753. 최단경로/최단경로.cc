#include <iostream>
#include <string>
#include <cstring>
#include <stack>
#include <vector>
#include <cmath>
#include <queue>
#include <algorithm>

using namespace std;

int V = 0;
int E = 0;
int K = 0;

priority_queue<pair<int, int>> pq;
int dist[20001];
vector  <pair<int, int>> graph[20001]; //목표지점, cost

void init();
void solve();

void init() {
    cin >> V >> E;
    cin >> K;

    for (int i = 0; i < 20001; i++) {
        dist[i] = 1000000;
    }

    for (int i = 0; i < E; i++) {
        int a = 0;
        int b = 0;
        int c = 0;
        cin >> a >> b>> c;

        graph[a].push_back({ b,c });
    }
}

void solve() {
    //다익스트라 알고리즘
    dist[K] = 0;
    pq.push({ 0,K });

    while (!pq.empty()) {
        int current = pq.top().second;
        int d = -pq.top().first;
        pq.pop();

        if (dist[current] < d) continue;

        for (int i = 0; i < graph[current].size(); i++) {
            int next = graph[current][i].first;
            int cost = graph[current][i].second;

            if (d + cost < dist[next]) {
                dist[next] = d + cost;
                pq.push({ -(d + cost),next });
            }
        }
    }

    //출력
    for (int i = 1; i <= V; i++) {
        if (i == K) cout << 0<<"\n";
        else if (dist[i] == 1000000) cout << "INF" << "\n";
        else cout << dist[i] << "\n";
    }
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
    init();
    solve();
    
    
    return 0;
}