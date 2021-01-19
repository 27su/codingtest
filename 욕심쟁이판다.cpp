//백준 : https://www.acmicpc.net/problem/1937
//참고: https://yabmoons.tistory.com/154

#include <bits/stdc++.h>
using namespace std;

int n;
int arr[505][505]={0, };
int result = 0;
int dp[505][505]={0, }; //dp[a][b]=c : 판다가 (a,b)에 있을때 최대로 살 수 있는 날 수
int dx[]={0,0,1,-1}, dy[]={1,-1,0,0};


int dfs(int x, int y){
    if(dp[x][y]) return dp[x][y];
    dp[x][y] = 1;

    for(int i=0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(0>nx||nx>n-1||0>ny||ny>n-1) continue;
        if(arr[x][y]>=arr[nx][ny]) continue;
        dp[x][y] = max(dp[x][y], dfs(nx,ny)+1);
    }
    return dp[x][y];
}

int main() {
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            scanf("%d", &arr[i][j]);
        }
    }
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            result = max(result, dfs(i, j));
        }
    }
    
    printf("%d", result);
    return 0;
}