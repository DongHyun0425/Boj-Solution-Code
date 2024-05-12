#include <string>
#include <vector>
#include <iostream>
using namespace std;
vector<int>v;
vector<int> answer;
vector<int> info;
int n;
int mymax = 0;
void mycheck() {
    int arrow = 0;
    int r_score = 0;
    vector<int>shoot;
    int a_score = 0;
    for (int i = 0; i < 10; i++) {
        if (v[i]) {
            arrow += (info[i] + 1);
            shoot.push_back(info[i] + 1);
        }
        else {
            shoot.push_back(0);
        }
    }

    for (int i = 0; i < 10; i++) {
        if (info[i] < shoot[i]) {
            r_score += (10 - i);
        }
        else if (info[i] > shoot[i]) {
            a_score += (10 - i);
        }
        else if (info[i] == shoot[i] && info[i] != 0) {
            a_score += (10 - i);
        }
    }

    //0점에다 남은 화살 전부 박기
    if (r_score > a_score && arrow <= n) {
        shoot.push_back(n - arrow);
      
        if(mymax<r_score-a_score){
            answer.clear();
            answer=shoot;
            mymax = r_score-a_score;
        }else if(mymax==r_score-a_score){

        for (int i = 10; i >= 0; i--) {
            if ((shoot[i]>0 || answer[i]>0) && shoot[i] > answer[i]) {
                answer.clear();
                answer = shoot;
                break;
            }
            else if ((shoot[i] > 0 || answer[i] > 0) && shoot[i] < answer[i]) {
                break;
            }
        }
        }
    }
}

void BT() {
    if (v.size() == 10) {
        mycheck();
        return;
    }

    for (int j = 0; j < 2; j++) {
        if (j == 0) {
            v.push_back(0);
            BT();
            v.pop_back();
        }
        else {
            v.push_back(1);
            BT();
            v.pop_back();
        }
    }
}
vector<int> solution(int N, vector<int> Info) {
    n = N;
    info = Info;
    for (int i = 0; i < 11; i++) {
        answer.push_back(0);
    }
    BT();
    int c=0;
    for(int i=0;i<answer.size();i++){
        if(answer[i]==0) c++;
    }
    if(c==11){
        answer.clear();
        answer.push_back(-1);
    }
    return answer;
}
