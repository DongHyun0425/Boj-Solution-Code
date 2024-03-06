#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
	int a = 0;
	cin >> a;
	vector<int> minus;
	vector<int> plus;
	int zerocnt = 0;
	int one = 0;
	for (int i = 0; i < a; i++) {
		int tmp;
		cin >> tmp;
		if (tmp > 0 && tmp !=1) plus.push_back(tmp);
		if (tmp == 1) one++;
		if (tmp < 0) minus.push_back(tmp);
		if (tmp == 0) zerocnt++;
	}

	sort(plus.begin(), plus.end(), greater<>());
	sort(minus.begin(), minus.end());

	int answer = 0;

	if (minus.size()>0 && minus.size() % 2 == 0) {
		for (int i = 0; i < minus.size() - 1; i++) {
			answer += (minus[i] * minus[i + 1]);
			i++;
		}
	}
	else if(minus.size()>0){
		queue<int>m;
		for (int i = 0; i < minus.size(); i++) {
			m.push(minus[i]);
		}
		//zerocnt가 있는경우
		if (zerocnt > 0 && m.size()>=3) {
			while (m.size() > 1) {
				int x = m.front();
				m.pop();
				int y = m.front();
				m.pop();
				answer += x * y;
			}
		}

		//zrocnt가 없는경우
		if (zerocnt == 0 && m.size() >= 3) {
			while (m.size() > 1) {
				int x = m.front();
				m.pop();
				int y = m.front();
				m.pop();
				answer += x * y;
			}
			answer += m.front();
		}else if (zerocnt == 0 && m.size() == 1) {
			answer += m.front();
		}
	}

	if (plus.size()>0 && plus.size() % 2 == 0) {
		for (int i = 0; i < plus.size() - 1; i++) {
			answer += (plus[i] * plus[i + 1]);
			i++;
		}
	}
	else if(plus.size()>0){
		if (plus.size() >= 3) {
			for (int i = 0; i < plus.size() - 2; i++) {
				answer += (plus[i] * plus[i + 1]);
				i++;
			}
			answer += plus[plus.size() - 1];
		}
		else if (plus.size() == 1) {
			answer += plus[0];
		}
	}

	cout << answer+one;
}