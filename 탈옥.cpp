// 백준 :  https://www.acmicpc.net/problem/9376

#include <bits/stdc++.h>
using namespace std;

char a[105][105];
vector <pair<int,int>> p;
int dist[105][105][3];
int h,w;

int dx[]={0,0,1,-1}, dy[]={1,-1,0,0};

void bfs(int index){
    queue <pair<int,int>> q;
    q.push({p[index].first, p[index].second});
    dist[p[index].first][p[index].second][index] = 0;
    
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(0>nx||nx>h+1||0>ny||ny>w+1||a[nx][ny]=='*') continue;
  
            if(a[nx][ny] == '.'){
                if(dist[nx][ny][index]==-1 || dist[nx][ny][index] > dist[x][y][index]){
                    dist[nx][ny][index] = dist[x][y][index];
                    q.push({nx,ny});
                } 
            }
            else if(a[nx][ny] == '#'){
                if(dist[nx][ny][index]==-1 || dist[nx][ny][index] > dist[x][y][index]+1){
                    dist[nx][ny][index] = dist[x][y][index]+1;
                    q.push({nx,ny});
                } 
            }
        }
    }
}

int main() {
    int T;
    scanf("%d", &T);
    for(int t=0; t<T; t++){
        memset(dist,-1,sizeof(dist));
        scanf("%d %d", &h, &w);
        for(int i=0; i<h+2; i++){
            for(int j=0; j<w+2; j++){
                if(i==0||i==h+1||j==0||j==w+1) a[i][j]='.';
                else scanf(" %1c", &a[i][j]);
                if(a[i][j]=='$'){
                    a[i][j] = '.';
                    p.push_back({i,j});
                }
            }
        }
        
        for(int i=0; i<3; i++) bfs(i);
        
        int result = INT_MAX;
        for(int i=0; i<h+2; i++){
            for(int j=0; j<h+2; j++){
                bool flag = false;
                for(int k=0; k<3; k++){
                    if(dist[i][j][k]==-1){
                        flag = true;
                        break;
                    }
                }
                if(flag) continue;
                int sum = dist[i][j][0] + dist[i][j][1] + dist[i][j][2];
                if(a[i][j]=='#') sum -= 2;
                if(result>sum) result = sum;
            }
        }
        printf("%d\n", result);
        
        p.clear();
    }
    
    return 0;
}