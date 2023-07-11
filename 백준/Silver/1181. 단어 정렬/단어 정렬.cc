#include <iostream>
#include <queue>
#include <algorithm>
#include <string.h>
using namespace std;

bool cmp(string a, string b) {
	if (a.length() < b.length()) {
		return true;
	}
	else if(a.length() == b.length()) {
		return a<b;
	}
	else { return false; }

}

int main() {
	vector <string> v;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		if (find(v.begin(), v.end(), s) == v.end())
			v.push_back(s);
	}

	sort(v.begin(), v.end(), cmp);

	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << '\n';
	}

	return 0;
}