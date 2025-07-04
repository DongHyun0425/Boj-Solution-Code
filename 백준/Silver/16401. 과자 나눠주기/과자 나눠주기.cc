#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

long long length = 0;
int M = 0;
int N = 0;
vector<long long> arr;
long long Start;
long long End;

bool check(int mid) {
	int num = 0;
	for (int i = 0; i < N; i++) {
		num += (arr[i] / mid);
		if (num >= M) return true;
	}
	return false;
}

int main() {
	cin >> M >> N;
	Start = 1;
	for (int i = 0; i < N; i++) {
		long long tmp = 0;
		cin >> tmp;
		arr.push_back(tmp);
	}

	sort(arr.begin(),arr.end());
	End = arr[N - 1];
	
	while (Start <= End) {
		long long mid = (Start + End) / 2;
		if (check(mid)) {
			length = mid;
			Start = mid + 1;
		}
		else {
			End = mid - 1;
		}
	}

	cout << length;
}	