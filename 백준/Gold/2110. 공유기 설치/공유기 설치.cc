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
int cnt = 0;
int N, C = 0;
vector <int> wifi;
int result = 0;
void binarySearch() {
	int start =1;
	int end = wifi[wifi.size() - 1]-wifi[0];
	while (start <= end) {
		int mid = (start + end) / 2;
		int before = wifi[0];
		for (int i = 1; i < wifi.size(); i++) {
			if (wifi[i]- before >= mid) {
				before = wifi[i];
				cnt++; 
			}
		}
		if (cnt >= C-1) {
			if (result < mid) {
				result = mid;
			}
			start = mid + 1;
		}
		else {
			end = mid - 1;
		}
		cnt = 0;
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> N >> C;

	for (int i = 0; i < N; i++) {
		int temp = 0;
		cin >> temp;
		wifi.push_back(temp);
	}
	sort(wifi.begin(), wifi.end());
	binarySearch();
	cout << result;
}