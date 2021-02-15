// 백준 : https://www.acmicpc.net/problem/20056

#include <bits/stdc++.h>
using namespace std;

int N,M,K;
int dx[]={-1,-1,0,1,1,1,0,-1}, dy[]={0,1,1,1,0,-1,-1,-1};

struct fireBall{
    int r,c,m,s,d;
};

vector <fireBall> arr[55][55];

void move(){
    vector <fireBall> temp[55][55];
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            if(arr[i][j].size()==0) continue;
            for(int k=0; k<arr[i][j].size(); k++){
                fireBall cur = arr[i][j][k];
               
                int nx = cur.r + dx[cur.d]*(cur.s%N);
                int ny = cur.c + dy[cur.d]*(cur.s%N);
                
                if (nx > N) nx -= N;
                if (ny > N) ny -= N;
                if (nx < 1) nx += N;
                if (ny < 1) ny += N;


                
                temp[nx][ny].push_back({nx,ny,cur.m,cur.s,cur.d});
            }
            
        }
    }
    
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            arr[i][j].assign(temp[i][j].begin(), temp[i][j].end());
        }
    }
}

void after(){
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            if(arr[i][j].size()<2) continue;
            int n1=0, n2=0; //짝수, 홀수
            int sumM=0, sumS=0; //합쳐진 질량 합, 합쳐진 속력 합
            int cnt = arr[i][j].size();
            for(int k=0; k<cnt;k++){
                if(arr[i][j][k].d%2==0) n1++;
                else n2++;
                sumM += arr[i][j][k].m;
                sumS += arr[i][j][k].s;
            }
            int d[4];
            if(n1==0||n2==0){
                for(int k=0; k<4; k++) d[k] = k*2;
            }
            else {
                for(int k=0; k<4; k++) d[k] = k*2+1;
            }
            
            arr[i][j].clear();
            
            if(sumM/5>0){
                for(int k=0; k<4; k++){
                    arr[i][j].push_back({i,j,sumM/5,sumS/cnt,d[k]});
                }
            }
        }
    }
}

int getResult(){
    int result = 0;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            if(arr[i][j].size()==0) continue;
            
            for(int k=0; k<arr[i][j].size(); k++){
                result += arr[i][j][k].m;
            }
        }
    }
    return result;
}

int main() {
    scanf("%d %d %d", &N, &M, &K);
    
    for(int i=0; i<M; i++){
        int r,c,m,s,d;
        scanf("%d %d %d %d %d", &r, &c, &m, &s, &d);
        arr[r][c].push_back({r,c,m,s,d});
    }
    
    for(int k=0; k<K; k++){
        move();
        after();
    }
    
    printf("%d", getResult());
    return 0;
}
