#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    queue<int>q1;
    queue<int>q2;
    long long sum1=0;
    long long sum2=0;
    for(int i=0;i<queue1.size();i++){
        q1.push(queue1[i]);
        sum1+=queue1[i];
        q2.push(queue2[i]);
        sum2+=queue2[i];
    }
    
    long answer = 0;
    int flag = 0;
    long tmp = queue1.size() * 2 + 10;
    while(answer<=tmp){
        if(sum2>sum1){
            q1.push(q2.front());
            sum1+=q2.front();
            sum2-=q2.front();
            q2.pop();
        }else if(sum1>sum2){
            q2.push(q1.front());
            sum2+=q1.front();
            sum1-=q1.front();
            q1.pop();
        }else{
            flag=1;
            break;
        }
        answer++;
    }
    if(flag==1){
    return answer;
    }else{
        return -1;
    }
}