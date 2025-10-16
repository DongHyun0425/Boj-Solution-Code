#include <iostream>
#include <string>
#include <cstring>
#include <stack>
#include <vector>
#include <cmath>
#include <queue>
#include <algorithm>

using namespace std;

char map[11][11];
bool visited[11][11][11][11];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
bool Find = false;


struct Edge {
    int x, y, cnt;
    Edge(int x, int y, int cnt) {
        this->x = x;
        this->y = y;
        this->cnt = cnt;
    }
};

queue<Edge>q;
int N, M;
int rx, ry, bx, by;


void move(int &x,int &y, int dx,int dy, int &cnt) {
    //벽이나, 구멍을 만날때까지 움직이기,반드시 벽이나, 구멍을 만나기때문에 map범위 조건연산을 하지 않아도됨
    while (1) {
        x += dx;
        y += dy;
        cnt++;

        if (map[x][y] == '#') {
            x -= dx;
            y -= dy;
            cnt--;
            break;
        }
        if (map[x][y] == 'O') {
            break;
        }
    }
}

void init() {
    //map 받기
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            char c = ' ';
            cin >> c;
            map[i][j] = c;

            //빨강인경우
            if (c == 'R') {
                rx = i;
                ry = j;
            }
            //파랑인경우
            if (c == 'B') {
                bx = i;
                by = j;
            }
        }
    }
}

void solve() {
    //빨강부터 큐에넣기
    q.push(Edge( rx,ry,0 ));
    q.push(Edge(bx, by, 0));
    visited[rx][ry][bx][by] = true;
    
    //큐가 빌때까지
    while (!q.empty()) {
        Edge red_Edge = q.front();
        q.pop();
        Edge blue_Edge = q.front();
        q.pop();

        if (red_Edge.cnt >= 10) continue;

        for (int i = 0; i < 4; i++) {
            int rx = red_Edge.x;
            int ry = red_Edge.y;
            int rcnt = 0;
            int bx = blue_Edge.x;
            int by = blue_Edge.y;
            int bcnt = 0;
            
            //빨강 움직이기
            move(rx, ry, dx[i], dy[i], rcnt);
            //파랑 움직이기
            move(bx, by, dx[i], dy[i], bcnt);

            //이거 한 결과가 결국 벽 바로전 위치나, 딱 구멍좌표임
            //1번 blue가 구멍에 떨어진경우 무조건 continue
            if (map[bx][by] == 'O') continue;
            //2번 빨강공이 빠진경우 1출력
            else if (map[rx][ry] == 'O') {
                cout << "1";
                Find = true;
                break;
            }
            else {
                //둘다 안떨어진경우
                //3-1두개가 같은 위치인경우,더 많이 움직인 얘를 한칸 위치조정시켜줘야함
                if (rx == bx && ry == by) {
                    if (rcnt > bcnt) {
                        rx -= dx[i];
                        ry -= dy[i];
                    }
                    else{
                        bx -= dx[i];
                        by -= dy[i];
                    }
                }

                if (!visited[rx][ry][bx][by]) {
                    q.push(Edge(rx, ry, red_Edge.cnt + 1));
                    q.push(Edge(bx, by, blue_Edge.cnt + 1));
                    visited[rx][ry][bx][by] = true;
                }
            }
        }

        if (Find) break;

    }
}



int main() {
	ios::sync_with_stdio(false); cin.tie(0);
    init();
    solve();
    if (!Find) cout << "0";
    return 0;
}