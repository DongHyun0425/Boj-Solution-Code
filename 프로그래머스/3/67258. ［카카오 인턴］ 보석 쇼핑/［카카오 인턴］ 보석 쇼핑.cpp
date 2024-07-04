#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

vector<int> solution(vector<string> gems) {
    vector<int> answer;
    answer.push_back(0);
    answer.push_back(0);
    
    map<string,int>map;
    int gCount=0;
    for(int i=0;i<gems.size();i++){
        string gem = gems[i];
        if(map.find(gem)==map.end()){
            gCount++;
            map[gem]++;
        }
    }
    
    map.clear();
    
    int start = 0;
    int end=0;
    int min_len = 100001;
    while(1){
        //보석이 모두 있는경우
        if(gCount==map.size()){
            //최소구간이라면 갱신
            if(end-start<min_len){
                min_len=end-start;
                answer[0]=start+1;
                answer[1]=end;
            }
            
            if(map[gems[start]]==1){
                map.erase(gems[start]);
            }else{
                map[gems[start]]--;
            }
            
            start++;
        }else if(end==gems.size()) break; //end가 끝까지 간경우 만약 aaaab인경우 위의 if문이 걸려서 ab까지 감
        else if(map.size()<gCount){
            map[gems[end]]++;
            end++;
        }
    }
    return answer;
}