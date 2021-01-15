// 백준 : https://www.acmicpc.net/problem/2667
#include <bits/stdc++.h>
using namespace std;

int arr[30][30];
int N;

int bfs(int x, int y){
    queue <pair<int,int>> q;
    arr[x][y] = 0;
    q.push({x,y});
    
    int dx[]={0,0,1,-1}, dy[]={1,-1,0,0};
    int cnt=0;
    
    while(!q.empty()){
        pair <int,int> cur = q.front();
        q.pop();
        cnt++;
        for(int i=0; i<4; i++){
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
            if(0>nx||nx>N-1||0>ny||ny>N-1) continue;
            if(arr[nx][ny]==0) continue;
            q.push({nx,ny});
            arr[nx][ny] = 0;
        }
    }
    
    return cnt;
}

int main() {
    scanf("%d", &N);
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            scanf("%1d", &arr[i][j]);
        }
    }
    
    vector <int> result;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(arr[i][j]){
                result.push_back(bfs(i,j));
            }
        }
    }
    
    sort(result.begin(), result.end());
    printf("%d\n", (int) result.size());
    for(int i=0; i<(int) result.size(); i++) printf("%d\n", result[i]);
    return 0;
}