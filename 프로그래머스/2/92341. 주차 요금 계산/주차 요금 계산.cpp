#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

map<string,vector<string>> record;
map<string,int> fee;

int makeInt(string time){
    string hour = time.substr(0,2);
    string min = time.substr(3,2);
    return stoi(hour)*60+stoi(min);
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    
    for(int i=0;i<records.size();i++){
        string tmp = records[i];
        string time = tmp.substr(0,5);
        string carNumber = tmp.substr(6,4);
        record[carNumber].push_back(time);
    }
    
    for(auto & pair : record){
        string carNumber = pair.first;
        int total = 0;
        vector<string> & v = pair.second;
        int x = 0;
        int y = 0;
        for(int i=0;i<v.size();i++){
            if(i%2==0){
                x=makeInt(v[i]);
            }else{
                y=makeInt(v[i]);
                total += (y-x);
                x=0;
                y=0;
            }
        }
        
        if(v.size() % 2 !=0){
            y = makeInt("23:59");
            total +=(y-x);
        }
        fee[carNumber] = total;
    }
    
    for(auto & pair : fee){
            cout<<pair.first<<": "<<pair.second<<"\n";
            int time = pair.second;
            if(time<=fees[0]){
                answer.push_back(fees[1]);
            }else{
                double a = (double)(time-fees[0])/fees[2];
                int b = (time-fees[0])/fees[2];
                int tmp=0;
                if(a-b>0){tmp=b+1;}else{
                    tmp = b;
                }
                answer.push_back(fees[1]+tmp*fees[3]);
            }
    }
    return answer;
}