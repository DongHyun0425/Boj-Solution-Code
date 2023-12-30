#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int graph[102][102];
bool visited[102][102];
int m, n, k = 0;
int cnt = 0;
int result = 0;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,1,-1 };

void dfs(int i,int j) {
    visited[i][j] = true;
    for (int a = 0; a < 4; a++) {       
            int nx = dx[a] + i;
            int ny = dy[a] + j;
            if (nx >= 0 && ny>=0 && nx < m && ny<n && graph[nx][ny] == 0 && !visited[nx][ny]) {
                cnt++;
                dfs(nx, ny);
            }
        }
 }

int main() {
	cin >> m >> n >> k;
    for (int i = 0; i < k; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        for (int j = y1; j < y2; j++)
            for (int k = x1; k < x2; k++)
                graph[j][k] = 1;
    }

    vector <int> total;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (graph[i][j] == 0 && !visited[i][j]) {
                cnt++;
                dfs(i, j);
                total.push_back(cnt);
                result++;
                cnt = 0;
            }
        }
    }

    sort(total.begin(), total.end());
    cout << result << "\n";
    for (int i = 0; i < total.size(); i++) {
        cout << total[i] << " ";
    }
}