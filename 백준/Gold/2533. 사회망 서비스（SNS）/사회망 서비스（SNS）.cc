#include <iostream>
#include <string>
#include <cstring>
#include <stack>
#include <vector>
#include <cmath>
#include <queue>
#include <algorithm>

using namespace std;
int N = 0;
int dp[1000002][2];
vector<int> map[1000002];

void init() {
    cin >> N;
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        map[a].push_back(b);
        map[b].push_back(a);
    }
}

void dfs(int node, int parent) {
    //리프초기화
    dp[node][0] = 0;
    dp[node][1] = 1;
    for (int i = 0; i < map[node].size(); i++) {
        int child = map[node][i];
        if (child == parent) continue;
        dfs(child, node);
        dp[node][0] += dp[child][1];
        dp[node][1] += min(dp[child][0], dp[child][1]);
    }
}

void solve() {
    dfs(1, 1);
    cout << min(dp[1][1], dp[1][0]);
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
    init();
    solve();
    return 0;
}