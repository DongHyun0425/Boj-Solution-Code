#include <string>
#include <vector>
#include <iostream>
#include <deque>
#include <cstring>
using namespace std;

deque<int>q;
bool visited[100] = { false, };
int tmp = 0;

void changeToFullDec() {
    int idx = 2;
    while (true) {
        if (q.size() <= idx - 1) break;
        idx *= 2;
    }
    int s = idx - 1 - q.size();
    for (int i = 0; i <= s; i++) q.push_front(0);
}

void makebit(long long n) {
    while (n != 1) {
        if (n % 2 == 0) {
            q.push_front(0);
        }
        else {
            q.push_front(1);
        }
        n /= 2;
    }
    q.push_front(1);
    changeToFullDec();
}

void mycheck(long long top, int flag, long long checksize) {
    int a = q[top];
    visited[top] = true;
    if (flag == 0 && a == 1) {
        tmp++;
        return;
    }

    if (top - checksize >= 0 && top + checksize < q.size() && !visited[top - checksize] && !visited[top + checksize]) {
        if (tmp == 0) {
            mycheck(top - checksize, a, checksize / 2);
        }
        if (tmp == 0) {
            mycheck(top + checksize, a, checksize / 2);
        }
    }
}

vector<int> solution(vector<long long> numbers) {
    vector<int> answer;
    for (int i = 0; i < numbers.size(); i++) {
        long long n = numbers[i];
        makebit(n);
        
        //애초에 rootnode가 0인경우
        if (q[q.size() / 2] == 0) {
            answer.push_back(0);
        }
        else {
            int checksize = q.size() / 2;
            if (checksize % 2 != 0) {
                checksize++;
            }
            mycheck(q.size() / 2, 1, checksize/2);
            if (tmp==0) {
                answer.push_back(1);
            }
            else {
                answer.push_back(0);
            }
        }

        //작업처리후 vclear
        q.clear();
        tmp = 0;
        for(int i=0;i<100;i++){
            visited[i]=false;
        }
    }
    return answer;
}