#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <cmath>
#include <tuple>

using namespace std;
 


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int L, C = 0;
    cin >> L >> C;
    vector<char> s;
    vector<int> temp;

    for (int i = 0; i < C; i++) {
        char c;
        cin >> c;
        s.push_back(c);
    }

    sort(s.begin(), s.end());

    for (int i = 0; i < L; i++) {
        temp.push_back(1);
    }

    for (int i = 0; i < C - L; i++) {
        temp.push_back(0);
    }
    
    do {
        string k = "";
        int acount = 0;
        int othercount = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (temp[i] == 1) {
                k+=s[i];
            }
        }
        for (int i = 0; i < k.length(); i++) {
            if (k[i] == 'a' || k[i] == 'e' || k[i] == 'i' || k[i] == 'o' || k[i] == 'u') {
                acount++;
            }
            else { othercount++; }
        }
        if (acount > 0 && othercount > 1) {
            cout << k << endl;
        }
    } while (prev_permutation(temp.begin(), temp.end()));

    return 0;
}