#include <string>
#include <vector>

using namespace std;
int map[500][500]={0,};
int result[500][500]={0,};
int solution(vector<vector<int>> triangle) {
    int answer = 0;
    int cnt=1;
    for(int i=0;i<triangle.size();i++){
        for(int j=0;j<cnt;j++){
            map[i][j]=triangle[i][j];
            result[i][j]=triangle[i][j];
        }
        cnt++;
    }
    
    for(int i=0;i<cnt-1;i++){
        for(int j=0;j<cnt-1;j++){
            int number1=result[i][j]+map[i+1][j];
            int number2=result[i][j]+map[i+1][j+1];
            
            if(result[i+1][j]<number1) result[i+1][j]=number1;
            
            if(result[i+1][j+1]<number2) result[i+1][j+1]=number2;
        }
    }
    int max=0;
    for(int i=0;i<cnt-1;i++){
        if(result[cnt-1][i]>max){
            max=result[cnt-1][i];
        }
    }
    return max;
}