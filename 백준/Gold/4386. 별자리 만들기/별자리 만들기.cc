#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <deque>
using namespace std;

int n = 0;
pair<float, float> star[101];
vector<pair<float, pair<float, float>>>v;
int parent[101];
float answer;

void init() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		float first = 0;
		float second = 0;
		cin >> first;
		star[i].first = first;
		cin >> second;
		star[i].second = second;
		parent[i] = i;
	}
}

void make_v() {
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			float x = star[i].first - star[j].first;
			float y = star[i].second - star[j].second;

			float dist = sqrt((x * x) + (y * y));
			v.push_back({ dist, { i,j } });
		}
	}
}

int find(int x) {
	if (parent[x] == x)return x;
	else return parent[x] = find(parent[x]);
}

void uni(int x, int y) {
	x = find(x);
	y = find(y);
	parent[y] = x;
}

bool sameparent(int x, int y) {
	x = find(x);
	y = find(y);
	if (x == y) return true;
	else return false;
}

void make_line() {
	for (int i = 0; i < v.size(); i++) {
		if (!sameparent(v[i].second.first, v[i].second.second)) {
			uni(v[i].second.first, v[i].second.second);
			answer += v[i].first;
		}
	}
}

int main() {
	init();
	make_v();
	sort(v.begin(), v.end());
	make_line();

	cout.precision(3);
	cout << answer;
}