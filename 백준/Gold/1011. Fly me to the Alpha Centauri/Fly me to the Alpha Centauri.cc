#include <cmath>
#include <iostream>
#include <vector>
#include <utility>
#include <string.h>
#include <algorithm>
using namespace std;

int main() {
	int num = 0;
	cin >> num;
	for (int i = 0; i < num; i++) {
		long long Answer = 0;
		//N은 최대 이동거리
		long long N = 0;
		long long start = 0;
		long long end = 0;
		cin >> start >> end;

		while (N * N <= end-start) {
			N++;
		}
		N--;

		Answer = 2 * N - 1;
		long long extra = (end - start) - (N * N);
		if (extra == 0) {
			//최대거리로 정확히 도착가능
			cout << Answer << "\n";
		}
		else {
			//최대거리안에 갈수 있음
			if (extra <= N) { Answer++; }
			else {
				//만약 13광년인경우 N이 3이다. (13-0)-3*3 = 4로 추가로 4만큼 더가야함 
				//4/3 = 1.3333 -> 올림 이므로 2
				extra = (long long)ceil((double)extra / (double)N);
				Answer += extra;
			}
			cout << Answer << "\n";
		}
	}
	return 0;
}