// 백준 : https://www.acmicpc.net/problem/17406

#include <bits/stdc++.h>
using namespace std;

struct Info{int r,c,s;};

int N,M,K;
int A[55][55]={0, }, T[55][55]={0, };
vector <Info> v;

void copy(){
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            T[i][j] = A[i][j];
        }
    }
}

int getMin(){
    int result = INT_MAX;
    for(int i=0; i<N; i++){
        int cnt = 0;
        for(int j=0; j<M; j++){
            cnt += T[i][j];
        }
        result = min(result, cnt);
    }
    return result;
}

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };


int change_D(int d){
    if(d==0) return 3;
    else if(d==1) return 2;
    else if(d==2) return 0;
    else return 1;
}

void rotate(int r, int c, int s){
    int sx = r-s;
    int sy = c-s;
    int ex = r+s;
    int ey = c+s;
    int turn_count = (ex-sx)/2;
    
    for(int i=0; i<turn_count; i++){
        int x = sx;
        int y = sy;
        int start = T[x][y];
        int d = 2;
        
        while(true){
            int nx = x+dx[d];
            int ny = y+dy[d];
            
            if(nx == sx && ny == sy){
                T[x][y] = start;
                break;
            }
            
            if(sx<=nx && nx <= ex-i && sy <= ny && ny <= ey-i){
                T[x][y] = T[nx][ny];
                x = nx;
                y = ny;
            }
            else d = change_D(d);
        }
        sx++;
        sy++;
    }
}

int main() {
    scanf("%d %d %d", &N,&M,&K);
    
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            scanf("%d", &A[i][j]);
        }
    }
    
    
    for(int k=0; k<K; k++){
        int r,c,s;
        scanf("%d %d %d", &r, &c, &s);
        v.push_back({r-1,c-1,s});
    }
    
    int result = INT_MAX;
    
    vector <int> index;
    for(int i=0; i<(int)v.size(); i++){
        index.push_back(i);
    }
    
    do{
        copy();
        for(int i=0; i<(int)index.size(); i++){
            int idx = index[i];
            rotate(v[idx].r, v[idx].c, v[idx].s);
        }
        result = min(result,getMin());
    }while(next_permutation(index.begin(),index.end()));
    
    printf("%d",result);
    return 0;
}
