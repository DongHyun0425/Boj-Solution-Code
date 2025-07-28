#include <string>
#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

/*
* 문제 해설
	팀원수 제한 x, 모든학생이 같은 팀 가능
	혼자하고싶으면 자기 선택 가능
	s1 -> s1선택, s1->s2->s3->,,,->sr이 반드시 s1을 선택해야함. 그래프? 유니온?
	ㅇㅎ 결국 s1 -> s2 -> s3 -> s1이런식으로 사이클이 존재해야지만 가능한거네
	학생수 100,000명
*/


vector<int> v;
bool check[100001];
bool done[100001];
int cnt; // 프로젝트 팀 결성

void dfs(int start) {
	//방문을 한번씩만 해야함.
	//방문을 안했다면
	int next = v[start];
	check[start] = true;
	//어차피 이미 다음 방문할애가 사이클이라면 더해놨음
	if (!check[next]) {
		dfs(next);
	}
	else if(!done[next]) {
		for (int i = next; i != start; i = v[i]) {
			cnt++;
		}
		//자기꺼
		cnt++;
	}
	done[start] = true;
	return;
}

int main(void) {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int T; cin >> T;
	
	while (T > 0) {
		T--;
		memset(done, false, sizeof(done));
		memset(check, false, sizeof(check));
		v.clear();
		int n = 0;
		cnt = 0;
		cin >> n;
		v.push_back(0);
		for (int i = 0; i < n; i++) {
			int a = 0;
			cin >> a;
			v.push_back(a);
		}
		for (int i = 1; i <= n; i++) {
			if (!check[i]) {
				dfs(i);
			}
		}
		cout << n-cnt << "\n";
	}
	return 0;
}