// 백준 : https://www.acmicpc.net/problem/2178

#include <bits/stdc++.h>

using namespace std;


int main() {
    int N,M;
    int dx[]={0,0,1,-1}, dy[]={1,-1,0,0};
    scanf("%d %d", &N, &M);
    int arr[N+1][M+1];
    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){
            scanf("%1d", &arr[i][j]);
        }
    }
    
    queue <pair<int,int>> q;
    bool check[N+1][M+1] = {0, };
    q.push({1,1});
    check[1][1] = true;
    int result[N+1][M+1] = {0, };
    result[1][1] = 1;
    
    while(!q.empty()){
        pair<int,int> cur = q.front();
        q.pop();
        for(int i=0; i<4; i++){
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
            if(1>nx||nx>N||1>ny||ny>M) continue;
            if(arr[nx][ny]==0) continue;
            if(check[nx][ny]){
                if(result[cur.first][cur.second]+1<result[nx][ny]){
                    q.push({nx,ny});
                    result[nx][ny] = result[cur.first][cur.second]+1;
                } 
            }
            else{
                check[nx][ny] = true;
                q.push({nx,ny});
                result[nx][ny] = result[cur.first][cur.second]+1;
            }
        }
    }
    printf("%d", result[N][M]);
    return 0;
}