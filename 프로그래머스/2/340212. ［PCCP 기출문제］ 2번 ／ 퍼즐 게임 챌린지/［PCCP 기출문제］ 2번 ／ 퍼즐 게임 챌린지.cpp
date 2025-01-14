#include <string>
#include <vector>
#include <iostream>

using namespace std;
int answer = 0;
vector<int> diffs;
vector<int> times;
long long limit = 0;

bool check(int level){
    long long total_time=0;
    for(int i=0;i<diffs.size();i++){
        //클경우
        if(level >= diffs[i]){
            total_time +=times[i];
        }else{
            int cnt = diffs[i]-level;
            total_time += (times[i]+times[i-1])*cnt + times[i];
        }
    }
    cout<<"총 시간: "<<total_time<<"\n";
    if(total_time<=limit) return true;
    return false;
}

void BS(){
    int start =1;
    int end = 100000;
    while(start<=end){
        int mid=(start+end)/2;
        cout<<"현재 level: "<<mid<<"\n";
        if(check(mid)){
            end = mid-1;
            answer=mid;
        }else{
            start = mid+1;
        }
    }
    
}
int solution(vector<int> diff, vector<int> time, long long limits) {
    diffs = diff;
    times = time;
    limit = limits;
    
    BS();
    return answer;
}