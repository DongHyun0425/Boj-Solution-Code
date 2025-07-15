#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <deque>
#include <stack>
using namespace std;

int main() {
	int x1, y1, x2, y2, x3, y3;
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

	int temp = ((x2 - x1) * (y3 - y2)) - ((y2 - y1) * (x3 - x2));
	if (temp > 0) {
		cout << "1";
	}
	else if (temp < 0) {
		cout << "-1";
	}
	else {
		cout << "0";
	}


}