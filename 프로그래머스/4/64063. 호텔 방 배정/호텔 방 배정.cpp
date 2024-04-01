#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

unordered_map<long long, long long> room;

long long getemptyidx(long long target){
    if(room[target]==0){
        //1번 방이 비어있는데 1번방을 원하면 1번을 return
        return target;
    }
    return room[target]=getemptyidx(room[target]);
}

vector<long long> solution(long long k, vector<long long> room_number) {
    vector<long long> answer;
    for(long long i=0;i<room_number.size();i++){
        long long temp = room_number[i];
        long long emptyidx = getemptyidx(temp);
        
        answer.push_back(emptyidx);
        room[emptyidx]=emptyidx+1;
    }
    return answer;
}