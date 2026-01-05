#include <iostream>
#include <string>
#include <cstring>
#include <stack>
#include <vector>
#include <cmath>
#include <queue>
#include <algorithm>

using namespace std;

struct Node {
    int x;
    int y;
    int cnt;
    int use;
};

int N;
int M;
bool visited[1001][1001][2] = {false,};
int map[1001][1001];
queue<Node>q;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int Answer = 100000000;

void init();
void solve();

void init() {
    cin >> N >> M;
    
    for (int i = 0; i < N; i++) {
        string s = "";
        cin >> s;
        for (int j = 0; j < M; j++) {
            map[i][j] = s[j] - '0';
        }
    }
}

void solve() {
    Node n = { 0,0,0,0 };
    q.push(n);
    visited[0][0][0] = true;
    
    while (!q.empty()) {
        Node n = q.front();
        int x = n.x;
        int y = n.y;
        int cnt = n.cnt;
        int use = n.use;
        q.pop();
        
        //cout << "현재 상태는 " << x << " " << y << " " << cnt << " " << use << "\n";

        //목적지에 다다른 경우
        if (x == N - 1 && y == M - 1 && cnt < Answer) {
            Answer = cnt;
        }

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            //map범위를 벗어나지 않고 && 일단 방문한적이 없는 좌표
            if (nx >= 0 && nx < N && ny >= 0 && ny < M && !visited[nx][ny][use]) {
                //벽을 부신적이 없는데, map좌표가 1인경우
                if (map[nx][ny] && !use) {
                    Node next_node = { nx,ny,cnt + 1,1 }; // 마지막 1 이 사용했다는것임
                    q.push(next_node);
                    visited[nx][ny][1] = true;
                }
                else if (!map[nx][ny]) {
                    Node next_node = { nx,ny,cnt + 1,use }; //map이 0이라면 그대로 넣기 
                    q.push(next_node);
                    visited[nx][ny][use] = true;
                }
            }
        }
    }
    
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
    init();
    solve();
    
    if (Answer == 100000000) cout << "-1";
    else cout << Answer+1;
    
    return 0;
}