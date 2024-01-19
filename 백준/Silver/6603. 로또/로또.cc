#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <cmath>
#include <tuple>
#include <map>
#include <string>
#include <vector>

using namespace std;
int depth = 0;
vector <int> v;
vector<int> lotto;
void BT(int depth,int temp) {
	if (depth == 6) {
		for (int i = 0; i < 6; i++) {
			cout << lotto[i] << " ";
		}
		cout << endl;
		//출력
		return;
	}
	for (int i = temp; i < v.size(); i++) {
		lotto.push_back(v[i]);
		BT(depth + 1, i + 1);
		lotto.pop_back();
	}

}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int k = 0;
	while (1) {
		cin >> k;
		if (k == 0) break;
		for (int i = 0; i < k; i++) {
			int temp = 0;
			cin >> temp;
			v.push_back(temp);
		}
		BT(0, 0);
		cout << endl;
		v.clear();
		lotto.clear();
	}
	return 0;

}