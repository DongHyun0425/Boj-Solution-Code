#include <string>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <stack>
using namespace std;
#define endl "\n"
using namespace std;

int N, K, Answer;

void Input() {
    cin >> N >> K;
}

int check(int x) {
    int cnt = 0;
    while (x > 0) {
        if (x % 2 == 1)cnt++;
        x /= 2;
    }
    return cnt;
}

void Solution() {
    if (N <= K) {
        cout << "0";\
    }
    else {
        while (1) {
            int temp = check(N);
            if (temp <= K) {
                break;
            }
            Answer++;
            N++;
        }
        cout << Answer;
    }

}

void Solve() {
    Input();
    Solution();
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // freopen("Input.txt", "r", stdin);
    Solve();

    return 0;
}
