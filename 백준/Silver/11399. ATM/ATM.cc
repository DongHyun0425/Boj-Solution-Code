#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int N;
	cin >> N;
	vector <int> v;
	for (int i = 0; i < N; i++) {
		int temp = 0;
		cin >> temp;
		v.push_back(temp);
	}
	sort(v.begin(), v.end());

	int total = 0;
	for (int i = 1; i < v.size(); i++) {
		v[i] = v[i] + v[i - 1];
	}
	for (int i = 0; i < v.size(); i++) {
		total += v[i];
	}
	cout << total;
}