#include <string>
#include <vector>
#include <iostream>
using namespace std;
vector <int> apeache;
int lion[11]={0,};
vector <int> answer;
int maxDiff = 0;
int N=0;

void check() {
    int temp[11] = { 0, };
    int costr = 0;
    int costa = 0;
    int cnt = 0;
    for (int i = 0; i < 10; i++) {
        //lion이 어피치를 10점에서 이겨야한다면
        if (lion[i] > 0) {
            costr += 10 - i;
            temp[i] = apeache[i] + 1;
            cnt += temp[i];
        }
        else {
            //만약 져야하면 안쏘는게 제일이득 어차피 이기는경우만 판단하니까
            temp[i] = 0;
            if (apeache[i] > 0) {
                costa += 10 - i;
            }
        }
    }
    //현재 내가 이기기위해서 쓴 화살이 n개보다 작거나 같으면 성립
    if (cnt <= N) {
        //작을경우 마지막에 전부 박는게 제일 이득
        temp[10] = N - cnt;

        //같은경우 작은거에 많이 박은게 이득
        if (costr - costa == maxDiff) {
            for (int i = 10; i >= 0; --i) {
                //뒤에서부터 확인
                if (temp[i] > answer[i]) {
                    //if해당되면 지워주고 answerclear해서 비워주고 넣어주면댐
                    maxDiff = costr - costa;
                    answer.clear();
                    for (int i = 0; i < 11; i++) {
                        answer.push_back(temp[i]);
                    }
                }
                //기존에 있던 답이 정답
                else if (temp[i] < answer[i]) {
                    break;
                }
            }
        }
        else if (costr - costa > maxDiff) {
            maxDiff = costr - costa;
            answer.clear();
            for (int i = 0; i < 11; i++) {
                answer.push_back(temp[i]);
            }
        }
    }
}

void dfs(int temp, int cnt, int N) {
    if (cnt == N) {
        check();
        return;
    }
    for (int i = temp; i < 11; i++) {
        lion[i] = 1;
        dfs(i + 1, cnt+1 , N);
        lion[i] = 0;
    }
}
vector<int> solution(int n, vector<int> info) {
    for(int i=0;i<10;i++){
    answer.push_back(0);
    }
    
    N=n;
    for(int i=0;i<info.size();i++){
        apeache.push_back(info[i]);
    }
    for (int i = 1; i < 11; i++) {
        dfs(0, 0, i);
    }
    if (maxDiff == 0) {
        answer.clear();
        answer.push_back(-1);
        return answer;
    }
    else {
        return answer;
   }
}