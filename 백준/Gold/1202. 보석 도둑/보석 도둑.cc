#include <string>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N = 0;
int K = 0;

pair<int, int> j[300001];
int bag[300001];
priority_queue <int> pq;

void init() {
	cin >> N >> K;

	for (int i = 0; i < N; i++) {
		int w, v;
		cin >> w >> v;

		j[i].first = w; //처음을 w로 넣는이유 -> sort할때 무게부터 해서 가장 작은무게부터 와야하므로,
		//그럼 왜 작은 무게부터 와야하는데? 무게가 2인 가방이면 j를 돌면서 담을수있는 보석을 전부 찾아야하니까 1,2무게 보석을 담기위해서
		j[i].second = v;
	}

	for (int i = 0; i < K; i++) {
		int temp = 0;
		cin >> temp;
		bag[i] = temp;
	}
}

void solve() {
	long long Answer = 0;

	sort(j, j + N);
	sort(bag, bag + K);

	int idx = 0;

	for (int i = 0; i < K; i++) {
		int b_weight = bag[i];
		//현재 무게 2

		//주얼리 idx안에서, 무게가 크거나 같은경우 pq에 넣기
		while (idx < N && b_weight >= j[idx].first) {
			pq.push(j[idx].second);
			idx++;
		}

		if (!pq.empty()) {
			Answer += pq.top();
			pq.pop();
		}
	}

	cout << Answer;
}

int main() {
	init();
	solve();
}