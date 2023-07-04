#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
     cin.tie(0);
	int count=0;
	int T;
	cin >> T;
	int N;

	pair<int, int> a[100000];
    for (int t = 0; t < T; t++)
    {	cin >> N;
        for (int i = 0; i < N; i++) {
            cin >> a[i].first >> a[i].second;
        }
        sort(a, a + N);
        int result = 1; 
        int interviewRank = a[0].second; //첫 번째 사원의 인터뷰 심사 성적
        for (int i = 1; i < N; i++)
        {
            if (a[i].second < interviewRank)
            {
                result++;
                interviewRank = a[i].second;
            }
        }
        cout << result << "\n";

    }
    return 0;
	
}