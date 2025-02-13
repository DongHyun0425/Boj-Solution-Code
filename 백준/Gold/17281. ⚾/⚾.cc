#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

int s[50][9];

void Move(bool(&ground)[3], int t, int& score, int& out) {
    if (t == 1) {
        if (ground[2]) {
            score++;
            ground[2] = false;
        }
        if (ground[1]) {
            ground[2] = true;
            ground[1] = false;
        }
        if (ground[0]) {
            ground[1] = true;
            ground[0] = false;
        }
        ground[0] = true;
    }
    if (t == 2) {
        if (ground[2]) {
            score++;
            ground[2] = false;
        }
        if (ground[1]) {
            score++;
            ground[1] = false;
        }
        if (ground[0]) {
            ground[2] = true;
            ground[0] = false;
        }
        ground[1] = true;
    }
    if (t == 3) {
        if (ground[2]) {
            score++;
            ground[2] = false;
        }
        if (ground[1]) {
            score++;
            ground[1] = false;
        }
        if (ground[0]) {
            score++;
            ground[0] = false;
        }
        ground[2] = true;
    }
    if (t == 4) {
        if (ground[2]) {
            score++;
            ground[2] = false;
        }
        if (ground[1]) {
            score++;
            ground[1] = false;
        }
        if (ground[0]) {
            score++;
            ground[0] = false;
        }
        score++;
    }
    if (t == 0) {
        out++;
    }
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 9; j++) {
            //1번이닝 3번타자 2에 들어있음
            cin >> s[i][j];
        }
    }

    //첫번째 순서인 1번타자 0번은 빼둠
    int np[8] = { 1,2,3,4,5,6,7,8 };
    int Answer = 0;
    int ans = 0;
    do {
        deque<int>h;
        //h에 타순대로 타자가 들어감
        for (int i = 0; i < 3; i++) h.push_back(np[i]);
        h.push_back(0);
        for (int i = 3; i < 8; i++)h.push_back(np[i]);

        int ining = 0; int score = 0;
        while (ining < n) {
            int out = 0;
            bool ground[3] = { false, };
            while (out < 3) {
                int cur = h.front();
                h.pop_front();
                //다음이닝에서 그대로 순서 이어서 진행해야하므로 queue에다가 뒤에 넣음
                h.push_back(cur);
                int Player = s[ining][cur];
                // 순서가 정해진 대로 선수들이 타석으로 출전.   
                Move(ground, Player, score, out);
            }
            ining++;
        }
        if (Answer < score)Answer = score;
    } while (next_permutation(np, np + 8));
    cout << Answer;
}