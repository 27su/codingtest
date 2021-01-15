// 백준 : https://www.acmicpc.net/problem/7576

#include <bits/stdc++.h>

using namespace std;

int arr[1005][1005];
int M,N;
int dx[]={0,0,1,-1}, dy[]={1,-1,0,0};

int checkEnd(){
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(arr[i][j]==0){
                int cnt = 0;
                for(int d=0; d<4; d++){
                    int nx = i + dx[d];
                    int ny = j + dy[d];
                    if(0>nx||nx>N-1||0>ny||ny>M-1) cnt++;
                    else if(arr[nx][ny]==-1) cnt++;
                }
                if(cnt==4) return -1;
                else return 0;
            } 
        }
    }
    
    return 1;
}


int bfs(){
    queue <pair<int,int>> q;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(arr[i][j]==1){
                q.push({i,j});
            } 
        }
    }
    
    int cnt=0;
    while(checkEnd()==0){
        if(q.empty()) return -1;
        cnt++;
        int size = q.size();
        for(int k=0; k<size; k++){
            pair <int,int> cur = q.front();
            q.pop();
            for(int i=0; i<4; i++){
                int nx = cur.first + dx[i];
                int ny = cur.second + dy[i];
                if(0>nx||nx>N-1||0>ny||ny>M-1) continue;
                if(arr[nx][ny]==0){
                    arr[nx][ny] = 1;
                    q.push({nx,ny});
                } 
            }
        }
        
    }
    return cnt;
}


int main() {
    scanf("%d %d",&M ,&N);
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            scanf("%d", &arr[i][j]);
        }
    }
    
    
    int day=0, end=0;
    end = checkEnd();
    if(end == -1) day = -1;
    else if(end == 1) day = 0;
    else day = bfs();
    printf("%d", day);
    return 0;
}