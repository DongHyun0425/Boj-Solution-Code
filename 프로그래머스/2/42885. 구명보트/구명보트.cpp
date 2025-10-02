#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

deque <int> dq;

int solution(vector<int> people, int limit) {
    int answer = 0;
    
    sort(people.begin(),people.end());
    
    for(int i=0;i<people.size();i++){
        dq.push_back(people[i]);
    }
    
    while(dq.size()>1){
        int big = dq.back();
        int small = dq.front();
        
        if(big+small<=limit) dq.pop_front();
        answer++;
        dq.pop_back();
    }
    if(!dq.empty()) answer++;
    
    return answer;
}