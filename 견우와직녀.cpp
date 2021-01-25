// 백준 : https://www.acmicpc.net/problem/16137

#include <bits/stdc++.h>

using namespace std;

int N, M;
int a[20][20]={0, };
vector <pair<int, int>> v;

int dx[]={0,1,0,-1}, dy[]={1,0,-1,0};

bool isPossible(int x, int y){
    bool d[4]={0, };
    int cnt = 0;
    for(int i=0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(0>nx||nx>N-1||0>ny||ny>N-1) continue;
        if(a[nx][ny] == 0) {d[i] = true; cnt++;}
    }
    
    if(cnt>=3) return false;
    for(int i=0; i<2; i++){
        if(d[i] && d[i+1]) return false;
    }
    return true;
}

int bfs(){
    queue <pair<int,int>> q;
    bool check[20][20]={0, };
    q.push({0,0});
    check[0][0] = true;
        
    int result_time[20][20]={0, };
        
    while(!q.empty()){
    int size = q.size();
        for(int t=0; t<size; t++){
            int cx = q.front().first;
            int cy = q.front().second;
            q.pop();
                
            for(int i=0; i<4; i++){
                int nx = cx + dx[i];
                int ny = cy + dy[i];
                if(0>nx||nx>N-1||0>ny||ny>N-1) continue;
                    
                int original = a[nx][ny];
                int next = result_time[cx][cy]+1;
                if(a[cx][cy]<2 && a[nx][ny]>=2){
                    while(next%a[nx][ny] != 0) next++;
                    a[nx][ny] = 1; 
                }
                    
                if(check[nx][ny]){
                    if(a[nx][ny]==1){
                        if(result_time[nx][ny]>next){
                            q.push({nx,ny});
                            result_time[nx][ny] = next; 
                        }
                        a[nx][ny] = original;
                    }
                }
                else if(a[nx][ny]==1){
                    q.push({nx,ny});
                    check[nx][ny] = true;
                    result_time[nx][ny] = next; 
                    a[nx][ny] = original;
                }
            }    
        }
    }
        
    
        
    return result_time[N-1][N-1];
}

int main() {
    scanf("%d %d", &N, &M);
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            scanf("%d", &a[i][j]);
        }
    }
    
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(a[i][j]==0){
                if(isPossible(i,j)) v.push_back({i,j});
            }
        }
    }
    
    int result = INT_MAX;
    int t = bfs();
    if(t!=0 && result>t) result = t;
    
    for(int i=0; i<(int)v.size(); i++){
        a[v[i].first][v[i].second] = M;
        int t = bfs();
        if(t!=0 && result>t) result = t;
        a[v[i].first][v[i].second] = 0;
    }
    
    
    printf("%d", result);
    return 0;
}
