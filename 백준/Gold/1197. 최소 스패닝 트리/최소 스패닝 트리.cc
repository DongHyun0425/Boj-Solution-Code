#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int parent[10001];//사이클 판별을 위한 배열

//유니온 파인드에서 썻던 부모 찾는 함수
int find(int x) {
	if (parent[x] == x)return x;
	else return parent[x] = find(parent[x]);
}
//부모 동일하게 merge해주는 함수
void uni(int x, int y) {
	x = find(x);
	y = find(y);
	parent[y] = x;
}

//사이클 발생하는 지 유무를 따지기 위함
bool sameparent(int x, int y) {
	x = find(x);
	y = find(y);
	if (x == y)return true;
	else return false;
}

int main() {
	int vertex, e;
	cin >> vertex >> e;
	int result = 0;
	vector<pair<int, pair<int, int>>>v;
	for (int i = 0; i < e; i++) {
		int from, to, cost;
		cin >> from >> to >> cost;
		v.push_back({ cost,{from,to} });
	}
	//cost기준으로 sort해줘야한다.=>그래야 그리디로 최소 경로 구할 수 있음
	sort(v.begin(), v.end());
	//부모 초기화
	for(int i = 1; i <= vertex; i++)parent[i] = i;
	//동일한 부모가 아닐때, merge해주고, result에다가 cost더하기
	//아직 더하지 않은 간선은 앞에 부모를 자기 자신으로 초기화해서
	//값이 자기 자신이다.즉 7,4를 연결할때 7은 부모가 1 이고 4는 부모가 4라는것이다.
	//그다음에 4랑 1 이랑 연결하려하면 이제 부모가 1로 동일해서 건너뛴다.	
	for (int i = 0; i < v.size(); i++) {
		if (!sameparent(v[i].second.first, v[i].second.second)) {
			uni(v[i].second.first, v[i].second.second);
			result += v[i].first;
		}
	}
	cout << result;
}