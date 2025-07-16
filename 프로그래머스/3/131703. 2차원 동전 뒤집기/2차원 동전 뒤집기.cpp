#include <string>
#include <vector>

using namespace std;
int n=0;
int m=0;

void rowflip(vector<vector<int>> & matrix, int row){
    for(int i=0;i<m;i++){
        matrix[row][i] = 1 - matrix[row][i];
    }
    
}

void colflip(vector<vector<int>> & matrix, int col){
    for(int i=0;i<n;i++){
        matrix[i][col]= 1-matrix[i][col];
    }
    
}

int solution(vector<vector<int>> beginning, vector<vector<int>> target) {
    int answer = 0;
    
    n=beginning.size();
    m=beginning[0].size();
    
    int minFlip=999999;
    for(int rowMask =0;rowMask<(1<<n);rowMask++){
        vector<vector<int>>tmp = beginning;
        int flip=0;
        for(int i=0;i<n;i++){
            if(rowMask & (1<<i)){
                rowflip(tmp,i);
                flip++;
            }
            
        }
        
        for(int i=0;i<m;i++){
            if(tmp[0][i] != target[0][i]){
                colflip(tmp,i);
                flip++;
            }
            
        }
        
        if(tmp == target && minFlip>flip) minFlip = flip;
    }
    
    if(minFlip == 999999) {
        answer = -1;
    }else{
        answer = minFlip;
    }
    
    return answer;
}