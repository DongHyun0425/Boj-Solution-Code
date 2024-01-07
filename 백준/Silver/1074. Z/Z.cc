#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <cmath>
#include <tuple>

using namespace std;
int n = 0; int a = 0; int b = 0;
int total = 0;

void ffind(int r, int c, int size) {
    if (a == r && b == c) {
        cout << total;
        return;
    }
    if (a < r + size && r <= a && b < c + size && c <= b) {
        ffind(r, c, size / 2);
        ffind(r, c + size / 2, size / 2);
        ffind(r + size / 2, c, size / 2);
        ffind(r + size / 2, c + size / 2, size / 2);
    }
    else {
        total += size * size;
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> a >> b;
    ffind(0, 0, pow(2, n));
    return 0;
}