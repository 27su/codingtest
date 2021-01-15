// 백준 : https://www.acmicpc.net/problem/10026

#include <bits/stdc++.h>
using namespace std;

char arr1[105][105],arr2[105][105];
int N;
bool check[105][105]={0, };
int dx[]={0,0,-1,1}, dy[]={1,-1,0,0};

void bfs(int x, int y, int index){
    char arr[105][105];
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(index==1) arr[i][j] = arr1[i][j];
            else arr[i][j] = arr2[i][j];
        }
    }
    char color = arr[x][y];
    queue <pair<int,int>> q;
    q.push({x,y});
    check[x][y] = true;
    
    while(!q.empty()){
        pair <int,int> cur = q.front();
        q.pop();
        for(int i=0; i<4; i++){
            int nx = cur.first+dx[i];
            int ny = cur.second+dy[i];
            if(0>nx||nx>N-1||0>ny||ny>N-1) continue;
            if(check[nx][ny]||arr[nx][ny]!=color) continue;
            check[nx][ny] = true;
            q.push({nx,ny});
        }
    }
}

int getNum(int index){
    int cnt = 0;
    memset(check,0,sizeof(check));
    
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(!check[i][j]){
                bfs(i,j, index);
                cnt++;
            }
        }
    }
    return cnt;
}

int main() {
    scanf("%d", &N);
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            scanf(" %1c", &arr1[i][j]);
            if(arr1[i][j] == 'G') arr2[i][j] = 'R';
            else arr2[i][j] = arr1[i][j];
        }
    }
    
    printf("%d %d", getNum(1), getNum(2));
    
   
    return 0;
}