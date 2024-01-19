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

int mmax = -1000000000;
int mmin = 1000000000;

int main() {
	int N = 0;
	cin >> N;
	vector<int>n;
	for (int i = 0; i < N; i++) {
		int temp = 0;
		cin >> temp;
		n.push_back(temp);
	}
	int oper[4] = { 0, };
	for (int i = 0; i < 4; i++) {
		int temp = 0;
		cin >> temp;
		oper[i] = temp;
	}
	vector<char> v;
	for (int i = 0; i < 4; i++) {
		int temp = oper[i];
		for (int j = 0; j < temp; j++) {
			if (i == 0) {
				v.push_back('+');
			}
			else if (i == 1) {
				v.push_back('-');
			}
			else if (i == 2) {
				v.push_back('*');
			}
			else if (i == 3) {
				v.push_back('/');
			}
		}
	}

	sort(v.begin(), v.end());
	
	do {
		int total = n[0];
		for (int i = 0; i < v.size(); i++) {
			if (v[i] == '+') {
				total += n[i + 1];
			}
			else if (v[i] == '-') {
				total -= n[i + 1];
			}
			else if (v[i] == '*') {
				total *= n[i + 1];
			}
			else if (v[i] == '/') {
				total /= n[i + 1];
			}
		}
		if (total > mmax) {
			mmax = total;
		}
		if (total < mmin) {
			mmin = total;
		}
	} while (next_permutation(v.begin(), v.end()));

	cout << mmax << "\n" << mmin;
}