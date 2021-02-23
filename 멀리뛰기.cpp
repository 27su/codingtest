// 프로그래머스 : https://programmers.co.kr/learn/courses/30/lessons/12914

#include <string>
#include <vector>

using namespace std;

long long solution(int n) {
    int dp[2000]={0, };
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;
    
    for(int i=3; i<=n; i++){
        for(int j=1; j<=2; j++){
            dp[i] += dp[i-j]; 
            dp[i] %= 1234567;
        }
    }
    
    return dp[n];
}
