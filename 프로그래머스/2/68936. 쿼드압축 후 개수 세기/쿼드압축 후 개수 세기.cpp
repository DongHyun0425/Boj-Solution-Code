#include <string>
#include <vector>

using namespace std;

int zero=0;
int one=0;
int map[1024][1024]={0,};
   vector<int> answer;

void find(int start, int end, int size){
    int a = map[start][end];
    for(int i=start;i<start+size;i++){
        for(int j=end; j<end+size;j++){
            if(a!=map[i][j]){
                find(start,end,size/2);
                find(start,end+size/2,size/2);
                find(start+size/2,end,size/2);
                find(start+size/2,end+size/2,size/2);
                return;
            }
        }
    }
    if(a==0){
        zero++;

    }else{
        one++;
    
    }
}

vector<int> solution(vector<vector<int>> arr) {
    for(int i=0;i<arr.size();i++){
        for(int j=0;j<arr.size();j++){
            map[i][j]=arr[i][j];
        }
    }
    
    find(0,0,arr.size());
    answer.push_back(zero);
    answer.push_back(one);
    return answer;
}