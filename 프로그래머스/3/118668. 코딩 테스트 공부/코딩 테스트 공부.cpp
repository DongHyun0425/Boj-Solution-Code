#include <string>
#include <vector>
#include <algorithm>

using namespace std;


int solution(int alp, int cop, vector<vector<int>> problems) {
    //문제를 푸는데 필요한 점수는 150이 최대
    int dp[152][152];
    
    int maxAlp = alp;
    int maxCop = cop;
    
    fill(&dp[0][0],&dp[151][152],9999999);
    dp[alp][cop] = 0; //시작값은 0임
    
    //순회하면서 각각의 max를 찾기
    for(auto problem : problems){
        maxAlp = max(maxAlp,problem[0]);
        maxCop = max(maxCop,problem[1]);
    }
    
    //기존의 alp와 cop가 가장 높은값이면 계산 필요 없음
    if(maxAlp == alp && maxCop == cop) return 0;
    
    //max를 넘어가는 값은 확인하지 않아도됨
    for(int i = alp; i<=maxAlp;i++){
        for(int j = cop; j<=maxCop;j++){
            //알고리즘 +1
            dp[i+1][j]=min(dp[i+1][j],dp[i][j]+1);
            //코딩력 +1
            dp[i][j+1] = min(dp[i][j+1],dp[i][j]+1);
            
            //문제를 풀어서 알고, 코딩력 올리기
            //현재 0,0이라면, 여기서 모든 문제를 확인해서 dp[2][0] 또는 dp[3][2]등으로 갈 수 있는지 확인
            for(auto problem : problems){
                //일단 문제를 풀수있는 알고, 코딩력이여야함
                if(i>=problem[0] && j>=problem[1]){
                    //만약 현재 알고,코딩력이 100,100인데 보상으로 100 100 이 주어지면 원래있던 dp[200][200] 과 dp[100][100]+cost를 비교할것임, out of bound 오류 안생기게, 최대 코딩,알고력을 넘어가면 무조건 최대 코딩,알고력으로 반환
                    int nextA = min(maxAlp,problem[2]+i);
                    int nextC = min(maxCop,problem[3]+j);
                    //해당 문제를 풀었을때의 점수와 기존에있던 문제의 점수를 비교
                    dp[nextA][nextC] = min(dp[nextA][nextC],dp[i][j]+problem[4]);
                }
            }
        }
    }
      return dp[maxAlp][maxCop];
}