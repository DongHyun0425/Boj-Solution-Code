#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <cmath>
#include <tuple>

using namespace std;
int map[101][101][101] = { 0 };
int visited[101][101][101] = { 0 };
queue <tuple<int, int, int>> q;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int dh[2] = { -1,1 };
int M, N, H = 0;
int mx = 0;
int zero_count = 0;
int nothing = 0;
void bfs() {
    while (!q.empty()) {
        int hh = get<0>(q.front());
        int mm = get<1>(q.front());
        int nn = get<2>(q.front());
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nh = hh;
            int nx = mm + dx[i];
            int ny = nn + dy[i];
            if (nx >= 0 && nx < N && ny >= 0 && ny < M && visited[nh][nx][ny] == 0 && map[nh][nx][ny] == 0) {
                visited[nh][nx][ny] += visited[hh][mm][nn] + 1;
                map[nh][nx][ny] = 1;
                q.push({ nh,nx,ny });
            }
        }
        if (hh-1 >= 0 && hh - 1 < H && visited[hh-1][mm][nn] == 0 && map[hh-1][mm][nn] == 0) {
            visited[hh - 1][mm][nn] += visited[hh][mm][nn] + 1;
            map[hh - 1][mm][nn] = 1;
            q.push({ hh-1,mm,nn });
        }
        if (hh + 1 >= 0 && hh + 1 < H && visited[hh + 1][mm][nn] == 0 && map[hh + 1][mm][nn] == 0) {
            visited[hh + 1][mm][nn] += visited[hh][mm][nn] + 1;
            map[hh + 1][mm][nn] = 1;
            q.push({ hh + 1,mm,nn });
        }
    }
}

void find() {
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < M; k++) {
                if (map[i][j][k] == 0) {
                   nothing++;
                   cout << "-1";
                   return;
                }
                else {
                    if (visited[i][j][k] > mx) {
                        mx = visited[i][j][k];
                    }
                }
            }
        }
    }
}


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> M >> N >> H;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < M; k++) {  
                int temp = 0;
                cin >> temp;
                map[i][j][k] = temp;
            }
        }
    }
 
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < M; k++) {
                if (visited[i][j][k] == 0 && map[i][j][k] == 1) {
                    visited[i][j][k] = 1;
                    q.push({ i,j,k });
                
                }
            }
        }
    }

    bfs();

    find();
    if (nothing == 0) {
        cout << mx - 1;
    }
    return 0;
}