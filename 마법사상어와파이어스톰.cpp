//백준 : https://www.acmicpc.net/problem/20058

#include <bits/stdc++.h>
using namespace std;

int N,Q;
int A[100][100];

int dx[]={0,0,1,-1},dy[]={1,-1,0,0};
int n;

void fireStorm(int L){
    int len = pow(2,L);
    
    int T[100][100]={0, };
    for(int i=0; i<n; i+=len){
        for(int j=0; j<n; j+=len){
            for(int y=0; y<len; y++){
                for(int x=0; x<len; x++){
                    T[x+i][len-1-y+j] = A[y+i][x+j]; //배열회전
                }
            }
        }
    }
    
    for(int i=0; i<n; i++) for(int j=0; j<n; j++) A[i][j] = T[i][j];
    
    queue <pair<int,int>> q;
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(A[i][j]==0) continue;
            int cnt = 0;
            for(int d=0; d<4; d++){
                int nx = i + dx[d];
                int ny = j + dy[d];
                if(0>nx||nx>n-1||0>ny||ny>n-1||T[nx][ny]==0) cnt++;
                if(cnt>1){
                    A[i][j]--;
                    break;
                }
            }
        }
    }
}


void getResult(){
    bool check[100][100]={0, };
    int result = 0;
    int sum = 0;
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            sum += A[i][j];
            if(check[i][j]||A[i][j]==0) continue;
            
            int cnt = 0;
            queue <pair<int,int>> q;
            q.push({i,j});
            check[i][j] = true;
            
            while(!q.empty()){
                pair<int,int> cur = q.front();
                q.pop();
                cnt++;
                
                for(int d=0; d<4; d++){
                    int nx = cur.first + dx[d];
                    int ny = cur.second + dy[d];
                    if(0>nx||nx>n-1||0>ny||ny>n-1) continue;
                    if(check[nx][ny]||A[nx][ny]==0) continue;
                    check[nx][ny] = true;
                    q.push({nx,ny});
                }
            }
            
            result = max(result, cnt);
        }
    }
    printf("%d\n", sum);
    printf("%d\n", result);
}

int main() {
    scanf("%d %d", &N, &Q);
    n = pow(2,N);
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            scanf("%d", &A[i][j]);
        }
    }
    
    for(int i=0; i<Q; i++){
        int L;
        scanf("%d", &L);
        fireStorm(L);
    }
    getResult();
    return 0;
}
