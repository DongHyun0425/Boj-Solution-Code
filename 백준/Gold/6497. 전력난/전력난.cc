#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

//1번 0,0이 될때까지 while(1) cin>>m>>n하고 m,n가 0이면 탈출
//2번 while내에서 map초기화해야함,
//3번
//3-1). parent초기화
//3-2). sorting
//3-3). find_parent()로 부모가 다르면, 연결 후 merge()호출, 만약 부모가 같으면 사이클 생기는것이므로 패스

int parent[200001] = { 0, };
int find_parent(int x) {
	if (x != parent[x]) {
		parent[x] = find_parent(parent[x]);
	}
	return parent[x];
}

void merge(int x, int y) {
	int a = find_parent(x);
	int b = find_parent(y);

	parent[b] = a;
}

int main() {

	while (1) {
		int m, n;
		int Answer = 0;
		//1번
		cin >> m >> n;
		if (m == 0 && n == 0)break;

		//2번
		vector<pair<int, pair<int, int>>>map;
		for (int i = 0; i < n; i++) {
			int a = 0;
			int b = 0;
			int cost = 0;
			cin >> a >> b >> cost;
			map.push_back({ cost,{a,b} });
		}
		//3-1.
		for (int i = 0; i < 200001; i++) {
			parent[i] = i;
		}
		//3-2).
		sort(map.begin(), map.end());

		//3-3).
		for (int i = 0; i < map.size(); i++) {
			int cost = map[i].first;
			int start = map[i].second.first;
			int end = map[i].second.second;

			if (find_parent(start) != find_parent(end)) {
				merge(start, end);
			}
			else {
				Answer += cost;
			}
		}
		cout << Answer << "\n";
	}
	
}