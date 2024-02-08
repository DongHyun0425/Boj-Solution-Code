#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <iostream>
#include <algorithm>
using namespace std;

int ability[20][20] = { 0, };
int N = 0;

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int temp = 0;
			cin >> temp;
			ability[i][j] = temp;
		}
	}

	vector<int>s;
	vector<int>temp;

	for (int i = 0; i < N; i++) {
		s.push_back(i);
	}

	for (int j = 0; j < N / 2; j++) {
		temp.push_back(1);
	}
	for (int j = 0; j < N / 2; j++) {
		temp.push_back(0);
	}

	int max = 1000000;
	bool check[101] = { false, };
	do {
		int start = 0;
		int link = 0;
		for (int i = 0; i < s.size(); i++) {
			if (temp[i] == 1) {
				check[i] = true;
			}
			else {
				check[i] = false;
			}
		}

		for (int i = 0; i < s.size(); i++) {
			for (int j = 0; j < s.size(); j++) {
				if (check[i] == true && check[j] == true) start += ability[i][j];
				if (check[i] == false && check[j] == false) link += ability[i][j];
			}
		}
		if (abs(start - link) < max) {
			max = abs(start - link);
		}
	} while (prev_permutation(temp.begin(), temp.end()));


	cout << max;
}