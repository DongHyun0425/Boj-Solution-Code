#include <iostream>
#include <string>
#include <cstring>
#include <stack>
#include <vector>
#include <cmath>
#include <queue>
#include <algorithm>

using namespace std;

bool isPalin = false;
string s = "";

//문자 비교위치 + 문자하나 삭제 여부
void fn(int start, int end, bool flag) {
    while (start <= end) {
        if (s[start] == s[end]) {
            start++;
            end--;
        }
        else if (!flag) {
            fn(start+1, end, true);
            if (isPalin) return;
            fn(start, end-1, true);
            return;
        }
        else {
            return;
        }
    }
    
    if (!flag) cout << "0" << "\n";
    else cout << "1" << "\n";
    
    isPalin = true;
    return;
}

void solve() {
    fn(0, s.size() - 1, false);
    if (!isPalin) cout << "2" << "\n";
}  

void init() {
    int T = 0;
    cin >> T;

    for (int i = 0; i < T; i++) {
        cin >> s;
        isPalin = false;

        solve();
    }
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
    init();
    return 0;
}