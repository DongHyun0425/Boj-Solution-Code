#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

vector<int>v;

int N;

bool check() {
	string s = "";
	for (auto t : v) {
		s += to_string(t);
	}
	int num = stoi(s);
	if (num < 2) return false;
	int a = (int)sqrt(num);
	for (int i = 2; i <= a; i++) if (num % i == 0) return false;
	return true;
}

void BT() {
	if (v.size() == N) {
		string s = "";
		for (auto t : v) {
			s += to_string(t);
		}
		cout << s << "\n";
		return;
	}

	for (int i = 0; i <= 9; i++) {
		v.push_back(i);
		if (check()) {
			BT();
		}
		v.pop_back();
	}
}

int main() {
	cin >> N;
	
	BT();
}
