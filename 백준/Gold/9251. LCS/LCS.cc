#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <cmath>
#include <tuple>

using namespace std;

string s1, s2;
vector<vector<int>>v;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> s1 >> s2;
    s1 = "0" + s1;
    s2 = "0" + s2;

    v.resize(s2.size(), vector<int>(s1.size()));

    for (int i = 0; i < s2.size(); i++) {
        for (int j = 0; j < s1.size(); j++) {
            if (i == 0 || j == 0) {
                v[i][j] = 0;
            }
            else if (s1[j] == s2[i]) {
                v[i][j] = v[i - 1][j - 1] + 1;
            }
            else {
                v[i][j] = max(v[i - 1][j], v[i][j - 1]);
            }
        }
    }
    cout << v[s2.size() - 1][s1.size() - 1];
    return 0;
}