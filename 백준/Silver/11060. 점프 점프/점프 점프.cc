#include <iostream>
#include <string>
#include <cstring>
#include <stack>
#include <vector>
#include <cmath>
#include <queue>
#include <algorithm>

int arr[1001];
int visited[1001];
int jump[1001];

int N = 0;
bool flag = false;
using namespace std;

void init();
void solve();

void init() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        jump[i] = 99999;
    }
}

void bfs() {
    queue<int> q;
    visited[0] = true;
    q.push(0);
    jump[0] = 0;

    while (!q.empty()) {
        int current = q.front();
        q.pop();
        int num = arr[current]; //점프 숫자 2
        
        if (current == N - 1) {
            flag = true;
            return;
        }

        for (int i = 0; i <= num; i++){
            int next = current + i; // 점프후 칸
            if (!visited[next]) {
                //방문하지 않았더라면
                q.push(next);
                visited[next] = true;
                if (jump[next] > jump[current] + 1) {
                    jump[next] = jump[current] + 1;
                }
            }
        }
    }
}

void solve() {
    bfs();
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
    init();
    solve();

    if (flag) {
        cout << jump[N - 1];
    }
    else {
        cout << -1;
    }
    return 0;
}