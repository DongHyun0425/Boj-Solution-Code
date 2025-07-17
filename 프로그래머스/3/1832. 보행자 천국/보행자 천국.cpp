#include <vector>
#include <iostream>
using namespace std;

int MOD = 20170805;


// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int m, int n, vector<vector<int>> city_map) {
    int map[510][510];
    int DP[510][510][2];
    
    for(int i=0;i<510;i++){
        for(int j=0;j<510;j++){
            for(int k=0;k<2;k++){
                DP[i][j][k]=0;
            }
        }
    }
    
    
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            map[i][j] = city_map[i-1][j-1];
        }
    }
    
    DP[1][1][0] = 1;
    
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            //왼쪽이 0인경우
            if(map[i][j-1]==0){
                DP[i][j][0]=(DP[i][j][0]+DP[i][j-1][0] + DP[i][j-1][1])%MOD;
            }
            //위쪽이 0인경우
            if(map[i-1][j]==0){
                DP[i][j][1] =(DP[i][j][1]+DP[i-1][j][0] + DP[i-1][j][1])%MOD;
            }
            
            //왼쪽이 2인경우
            if(map[i][j-1]==2){
                DP[i][j][0] =  (DP[i][j][0]+DP[i][j-1][0])%MOD;
            }
            //위쪽이 2인경우
            if(map[i-1][j]==2){
                DP[i][j][1]=(DP[i][j][1]+DP[i-1][j][1])%MOD;
            }
            
        }
    }
    
  /*  for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            cout<<DP[i][j][0]<<DP[i][j][1]<<" ";
        }
        cout<<"\n";
    }*/
    
    return (DP[m][n][0]+DP[m][n][1])%MOD;
    
}