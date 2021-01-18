// 백준 : https://www.acmicpc.net/problem/14620

#include<bits/stdc++.h>
using namespace std;

int N;
int m[205][205]={0, };
bool visited[205][205]={0, };
int ret=INT_MAX;
int dx[]={0,0,1,-1}, dy[]={1,-1,0,0};

bool check(int x, int y){
    if(visited[x][y]) return false;
    for(int i=0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(0>nx||nx>N-1||0>ny||ny>N-1) return false;
        if(visited[nx][ny]) return false;
    }
    return true;
}

int getCost(int x, int y){
    int sum=m[x][y];
    visited[x][y] = true;
    for(int i=0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        sum += m[nx][ny];
        visited[nx][ny] = true;
    }
    return sum;
}

void cancle(int x, int y){
    visited[x][y] = false;
    for(int i=0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        visited[nx][ny] = false;
    }
}

void getResult(int sum, int index){
    if(index==0){
        ret = min(ret, sum);
        return;
    }
    
    for(int i=1; i<N-1; i++){
        for(int j=1; j<N-1; j++){
            if(check(i,j)){
                int cost = getCost(i,j);
                getResult(sum+cost, index-1);
                cancle(i,j);
            }
        }
    }
}

 
int main(){
    scanf("%d", &N);
    
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            scanf("%d", &m[i][j]);
        }
    }
    getResult(0,3);
    printf("%d",ret);
    
    return 0;
}