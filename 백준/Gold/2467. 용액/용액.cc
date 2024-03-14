#include <iostream>
using namespace std;
#include <vector> 
#include <algorithm>
using namespace std;

int main() {
	int n = 0;
	cin >> n;
	vector<long long int>v;
	for (int i = 0; i < n; i++) {
		long long int t = 0;
		cin >> t;
		v.push_back(t);
	}
	int start = 0;
	int end = v.size() - 1;
	long long int minimum = 2000000000;
	long long int ra, rb;
	while (start < end) {
		int t = v[start] + v[end];
		if (minimum > abs(t)) {
			minimum = abs(t);
			ra = v[start];
			rb = v[end];
		}
		if (t == 0) break;
		else if (t < 0) start++;
		else end--;
	}
	cout << ra << "\n";
	cout << rb << "\n";
}