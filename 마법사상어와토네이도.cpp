// 백준 : https://www.acmicpc.net/problem/20057
#include <bits/stdc++.h>
using namespace std;

int N;
int A[500][500];
int dx[]={0,1,0,-1,-1,1,1,-1},dy[]={-1,0,1,0,-1,-1,1,1};
int result = 0;

void cal(int x, int y, int nx, int ny, double r, int original){
    int sum = (double)original*r;
    if(0>nx||nx>N-1||0>ny||ny>N-1){
        result += sum;
    }
    else{ 
        A[nx][ny] += sum;
    }
    A[x][y] -= sum;
}

void move(int x, int y, int d){
    int original = A[x][y];
    
    cal(x,y,x+dx[d]*2,y+dy[d]*2,0.05,original);
    cal(x,y,x+dx[(d+1)%4],y+dy[(d+1)%4],0.07,original);
    cal(x,y,x+dx[(d+1)%4]*2,y+dy[(d+1)%4]*2,0.02,original);
    cal(x,y,x+dx[(d+3)%4],y+dy[(d+3)%4],0.07,original);
    cal(x,y,x+dx[(d+3)%4]*2,y+dy[(d+3)%4]*2,0.02,original);
    
    cal(x,y,x+dx[(d+4)%4+4],y+dy[(d+4)%4+4],0.1,original);
    cal(x,y,x+dx[(d+5)%4+4],y+dy[(d+5)%4+4],0.1,original);
    cal(x,y,x+dx[(d+6)%4+4],y+dy[(d+6)%4+4],0.01,original);
    cal(x,y,x+dx[(d+7)%4+4],y+dy[(d+7)%4+4],0.01,original);
    
    int nx = x + dx[d];
    int ny = y + dy[d];
    if(0>nx||nx>N-1||0>ny||ny>N-1){
        result += A[x][y];
    }
    else A[nx][ny] += A[x][y];
    A[x][y] = 0;
}

int main() {
    scanf("%d", &N);
    
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            scanf("%d", &A[i][j]);
        }
    }
    
    int x=N/2, y=N/2;
    int len=1, d=0;
    bool flag = false;
    
    while(true){
        for(int i=0; i<2; i++){
            for(int j=0; j<len; j++){
                x += dx[d];
                y += dy[d];
                move(x,y,d);
                if(x==0&&y==0) flag = true;
                if(flag) break;
            }
            if(flag) break;
            d = (d+1)%4;
        }
        if(flag) break;
        len++;
    }
    printf("%d", result);
    return 0;
}
