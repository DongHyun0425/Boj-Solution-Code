#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	string N;
	cin >> N;

	int length = 0;
	vector <int> v;
	vector<int> ::iterator iter;
	int count = 0;
	int zc=0;
	for (int i = 0; i < N.length(); i++) {
		char a = N[i];
		count += a - 48;
		if (a == '0') { zc++; }
		v.push_back(a-48);
	}

	if (zc == 0 || count % 3 != 0) {
		cout << -1;
	}
	else {
		string a;
		sort(v.rbegin(), v.rend());
		for (iter = v.begin(); iter != v.end(); iter++) { a+=to_string(*iter); }
		cout << a;
	}


	return 0;
}