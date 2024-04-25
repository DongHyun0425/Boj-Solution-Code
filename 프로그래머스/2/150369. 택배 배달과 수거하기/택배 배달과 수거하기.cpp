#include <string>
#include <vector>
#include <iostream>

using namespace std;

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long answer = -1;
    for (int i = n-1; i >= 0; --i) {
        int flag = 0;
        if (deliveries[i] > 0 || pickups[i] > 0) {
            flag = i;
            //give box
            int checkbox = 0;
            for (int j = i; j >= 0; j--) {
                if ((checkbox + deliveries[j]) <= cap) {
                    checkbox += deliveries[j];
                    deliveries[j] = 0;
                }
                else {
                    int tmp = cap - checkbox;
                    checkbox = cap;
                    deliveries[j] -= tmp;
                    break;
                }
            }

            //get box
            int getbox = 0;
            for (int j = i; j >= 0; j--) {
                if ((getbox + pickups[j]) <= cap) {
                    getbox += pickups[j];
                    pickups[j] = 0;
                }
                else {
                    int tmp = cap - getbox;
                    getbox = cap;
                    pickups[j] -= tmp;
                    break;
                }
            }
            answer += (i + 1) * 2;
            if (deliveries[flag] > 0 || pickups[flag] > 0) i = flag+1;
        }
    }
    return answer + 1;
}