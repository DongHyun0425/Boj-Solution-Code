#include <iostream>
#include <string>
#include <cstring>
#include <stack>
#include <vector>
#include <cmath>
#include <queue>
#include <algorithm>

using namespace std;

int Target = 0;
int arr[2002][2002] = { 0, };
void init() {
    cin >> Target;
    
    for (int i = 0; i < 2002; i++) {
        for (int j = 0; j < 2002; j++) {
            arr[i][j] = 1000000;
        }
    }
}

void solve() {
    // Screen, Clip, Time
    queue<pair<pair<int, int>, int>>q;
    arr[1][0] = 0;
    q.push({ {1,0},0 });

    while (!q.empty()) {
        int Screen = q.front().first.first;
        int Clip = q.front().first.second;
        int Time = q.front().second;
        q.pop();

        if (Screen == Target) {
            cout << Time;
            break;
        }

        //step 1: 화면에 있는 이모티콘을 모두 복사해서 클립보드에 저장한다.
        int step1_Clip = Screen;
        if (Time+1 < arr[Screen][step1_Clip]) {
            arr[Screen][step1_Clip] = Time+1;
            q.push({ {Screen,step1_Clip},Time + 1 });
        }

        //step 2: 클립보드에 있는 모든 이모티콘을 화면에 붙여넣기 한다.
        int step2_Screen = Screen + Clip;
        if (step2_Screen<2002 && Time + 1 < arr[step2_Screen][Clip]) {
            arr[step2_Screen][Clip] = Time + 1;
            q.push({ {step2_Screen,Clip},Time + 1 });
        }

        //step 3: 화면에 있는 이모티콘 중 하나를 삭제한다.
        int step3_Screen = Screen-1;
        if ( step3_Screen>=0 && Time + 1 < arr[step3_Screen][Clip]) {
            arr[step3_Screen][Clip] = Time + 1;
            q.push({ {step3_Screen,Clip},Time + 1 });
        }
    }

}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
    init();
    solve();
    return 0;
}