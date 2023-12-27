#include <iostream>
#include <vector>

using namespace std;
vector <pair<int, int>> house;
vector <pair<int, int>>chicken;
int N, M = 0;

int total = 1000000;
void Combi(vector<pair<int, int>>& chicken, vector<pair<int, int>>& res, int start) {
	if (res.size() == M) {
		int tt = 0;
		for (int i = 0; i < house.size(); i++) {
			int Max = 1000000;
			for (int j = 0; j < M; j++) {
				int sum = 0;
				int garo, sero = 0;
				if (house[i].first > res[j].first) {
					garo = house[i].first - res[j].first;
				}
				else {
					garo = res[j].first - house[i].first;
				}

				if (house[i].second > res[j].second) {
					sero = house[i].second - res[j].second;
				}
				else {
					sero = res[j].second - house[i].second;
				}

				sum = garo + sero;
				if (sum < Max) { Max = sum; }
			}
			tt += Max;
		}
		if (total > tt) {
			total = tt;
		}
	}

	for (int i = start; i < chicken.size(); i++) {
		res.push_back({ chicken[i].first, chicken[i].second });
		Combi(chicken, res, i + 1);
		res.pop_back();
	}
}

int main() {
	int Map[51][51] = { 0, };
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			int a = 0;
			cin >> a;
			Map[i][j] = a;
		}
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (Map[i][j] == 1) {
				house.push_back({ i,j });
			}
			else if (Map[i][j] == 2) {
				chicken.push_back({ i, j });
			}
		}
	}
	vector <pair<int, int>> res;
	Combi(chicken, res, 0);
	cout << total;
}