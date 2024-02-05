#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int main() {
	int n = 0;
	cin >> n;
	vector<long long int>v;
	int resulta = 0;
	int resultb = 0;
	for (int i = 0; i < n; i++) {
		long long int temp = 0;
		cin >> temp;
		v.push_back(temp);
	}

	sort(v.begin(), v.end());

	long long int min = 2000000000;
	long long int start = 0;
	long long int end = v.size()-1;

	while (start < end) {
		if (abs(v[start] + v[end]) < min) {
			min = abs(v[start] + v[end]);
			resulta = v[start];
			resultb = v[end];
		}

		if (v[start] + v[end] < 0) {
			start++;
		}
		else if (v[start] + v[end] > 0) {
			end--;
		}
		else {
			resulta = v[start];
			resultb = v[end];
			break;
		}
	}

	cout << resulta <<" "<< resultb;

}