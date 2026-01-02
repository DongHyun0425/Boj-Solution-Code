#include <iostream>
#include <string>
#include <cstring>
#include <stack>
#include <vector>
#include <cmath>
#include <queue>
#include <algorithm>

long long L = 0;
long long R = 0;

using namespace std;

void init();
void solve();

void init() {
    cin >> L;
    cin >> R;
}

bool comp_num() {
    long long l = L;
    long long r = R;
    int l_cnt = 0;
    int r_cnt = 0;

    //l자리수 계산
    while (l > 0) {
        l /= 10;
        l_cnt++;
    }

    //r자리수 계산
    while (r > 0) {
        r /= 10;
        r_cnt++;
    }

    if (l_cnt == r_cnt) {
        return true;
    }
    return false;
}

void solve() {
    //자리수가 애초에 다른경우
    if (!comp_num()) {
        cout << "0";
        return;
    }

    //자리수가 같은 경우
    string l = to_string(L);
    string r = to_string(R);

    int eight_cnt = 0;
    for (int i = 0; i < l.size(); i++) {
        //숫자가 다른경우
        if (l[i] != r[i]) {
            cout << eight_cnt;
            return;
        }
        else if(l[i]!='8') {
            //숫자가 같은데 8이 아닌경우
            continue;
        }
        else {
            eight_cnt++;
        }
    }

    cout << eight_cnt;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
    init();
    solve();

    return 0;
}