#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<vector<pair<int,int>>> graph;
bool visited[10001];
int departure, arrival;
int Answer = 0;

void init() {
    cin >> N >> M;
    graph.assign(N+1, {});
    for (int i = 0; i < M; i++) {
        int d, a, cost;
        cin >> d >> a >> cost;
        graph[d].push_back({a, cost});
        graph[a].push_back({d, cost});
    }
    cin >> departure >> arrival;
}

bool bfs(int weight) {
    queue<int> q;
    q.push(departure);
    visited[departure] = true;

    while (!q.empty()) {
        int n = q.front();
        q.pop();

        for (auto &edge : graph[n]) {
            int next = edge.first;
            int cost = edge.second;

            if (!visited[next] && cost >= weight) {
                if (next == arrival) return true;
                visited[next] = true;
                q.push(next);
            }
        }
    }
    return false;
}

void solve() {
    int start = 1, end = 1000000000;

    while (start <= end) {
        int mid = (start + end) / 2;
        fill(visited, visited + N + 1, false);

        if (bfs(mid)) {
            Answer = mid;
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    init();
    solve();
    cout << Answer;
}
