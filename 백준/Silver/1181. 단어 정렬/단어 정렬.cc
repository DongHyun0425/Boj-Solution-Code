#include <iostream>
#include <queue>
#include <algorithm>
#include <string.h>
using namespace std;

bool cmp(string a, string b) {
	if (a.length() == b.length()) {
		return a < b; //그냥 그대로 a<b로 해서 b가 더 크게 오름차순으로 정렬
	}
	else {
		return a.length() < b.length();//만약 길이가 다르면 b의 길이가 더 길어야만 오름차순으로 정렬
	}
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