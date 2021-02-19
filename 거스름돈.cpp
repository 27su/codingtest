// 프로그래머스 : https://programmers.co.kr/learn/courses/30/lessons/12907

#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> money) {
    vector <int> dp(n+1,0);
    dp[0] = 1;
    for(int coin : money){
        for(int i=coin; i<=n; i++){
            dp[i] += dp[i-coin];
            dp[i] %= 1000000007;
        }
    }
    
    return dp[n];
}
