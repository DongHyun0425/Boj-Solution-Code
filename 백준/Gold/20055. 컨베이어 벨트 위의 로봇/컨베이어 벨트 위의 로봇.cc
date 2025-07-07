#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <deque>
using namespace std;

int N;
int K;
deque<int> conv;
deque<bool> robot;
int result = 0;

void init() {
	cin >> N;
	cin >> K;

	for (int i = 0; i < 2 * N; i++) {
		int tmp;
		cin >> tmp;
		conv.push_back(tmp);
		robot.push_back(false);
	}
}

void rotate_conv() {
	conv.push_front(conv.back());
	conv.pop_back();

	robot.push_front(robot.back());
	robot.pop_back();

	//언제든지 N-1에 로봇이 오면 False를 박아야함
	robot[N - 1] = false;
}

void rotate_robot() {
	for (int i = N - 2; i >= 0; i--) {
		//그자리에 로봇이 있고,다음자리에 로봇이없고, 다음자리가 내구도가 있어야하고
		if (robot[i] && !robot[i + 1] && conv[i + 1] > 0) {
			robot[i + 1] = true;
			conv[i + 1]--;
			robot[i] = false;
		}
	}
	//항상 마지막 N-1은 false로 만들어줘야함
	robot[N - 1] = false;
}

void put_robot() {
	//0번쨰 자리에 robot이 없고, 내구도가 있어야함
	if (!robot[0] && conv[0] > 0) {
		robot[0] = true;
		conv[0]--;
	}
}

bool check_zero() {
	int cnt = 0;
	for (int i = 0; i < 2 * N; i++) {
		if (conv[i] == 0)cnt++;
	}
	if (cnt >= K)return true;
	return false;
}

int main() {
	init();

	while (1) {
		bool flag = true;
		result++;
		//컨베이어 벨트 회전
		rotate_conv();
		//로봇 회전
		rotate_robot();
		//로봇 올리기
		put_robot();
		//내구도 체크
		flag=check_zero();
		if (flag) break;
	}
	cout << result;
}
