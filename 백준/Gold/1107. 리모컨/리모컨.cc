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
bool arr[11];
int Answer = 0;
void init();
void solve();

void init() {
    cin >> N;

    for (int i = 0; i < 11; i++) {
        arr[i] = true;
    }

    int tmp = 0;
    cin >> tmp;
    for (int i = 0; i < tmp; i++) {
        int t = 0;
        cin >> t;
        arr[t] = false;
    }
}  


void solve() {
    //초기상태
    Answer = abs(100 - N); //102 - 100 이면 2번만에 갈수있음

    for (int i = 0; i < 1000000; i++) {
        string s = to_string(i);
        bool flag = true;
        for (int j = 0; j < s.size(); j++) {
            char c = s[j];
            //cout << "해당 자리숫는: " << c << "\n";
            if (!arr[c - '0']) {
                flag = false;
                break;
            }
        }
        if (flag) {
            //전부 누를 수 있는 번호들임.
            int temp = s.size() + abs(N - i); // N이 5508이고, i가 5506 이라면 4 + 2 = 6;

            //cout << "누를수있는 번호: " << i << " " << temp << "번 누름" << "\n";
            if (Answer > temp) Answer = temp;
        }
    }

}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
    init();
    solve();
  
    cout << Answer;
    return 0;
}