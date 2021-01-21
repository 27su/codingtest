//백준 : https://www.acmicpc.net/problem/10711

#include <bits/stdc++.h>
using namespace std;

int arr[1005][1005]={0, };
int H,W;

int dx[]={0,0,1,-1,1,-1,1,-1}, dy[]={1,-1,0,0,1,-1,-1,1};

int bfs(){ 
    queue <pair<int, int>> q;
    
    for(int i=0; i<H; i++){
        for(int j=0; j<W; j++){
            if(arr[i][j]==0) {
                q.push({i,j});
            }
        }
    }
    
    int day = -1;
    while(!q.empty()){
        day++;
        int size = q.size();
        for(int s=0; s<size; s++){
            pair <int,int> cur = q.front();
            q.pop();
            for(int i=0; i<8; i++){
                int nx = cur.first + dx[i];
                int ny = cur.second + dy[i];
                if(0>nx||nx>H-1||0>ny||ny>W-1) continue;
                if(arr[nx][ny] == 0) continue;
                arr[nx][ny]--;
                if(arr[nx][ny]==0) q.push({nx,ny});
            }
        }
    }
    
    return day;
}


int main() {
    scanf("%d %d", &H, &W);
    for(int i=0; i<H; i++){
        for(int j=0; j<W; j++){
            char temp;
            scanf(" %c", &temp);
            if(temp == '.') arr[i][j] = 0;
            else arr[i][j] = (temp-'0');
        }
    }
    printf("%d", bfs());
    return 0;
}