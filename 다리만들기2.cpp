//백준 : https://www.acmicpc.net/problem/17472

#include <bits/stdc++.h>
using namespace std;

int N,M;
int A[20][20];
int p[10];
int dx[]={1,0,-1,0},dy[]={0,1,0,-1};
int n=0;
vector <pair<int,pair<int,int>>> vt;

void getIndex(){
    bool check[20][20]={0, };
    
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(!check[i][j]&&A[i][j]!=0){
                n++;
                check[i][j] = true;
                A[i][j] = n;
                queue <pair<int,int>> q;
                q.push({i,j});
                while(!q.empty()){
                    int x = q.front().first;
                    int y = q.front().second;
                    q.pop();
                    
                    for(int d=0; d<4; d++){
                        int nx = x + dx[d];
                        int ny = y + dy[d];
                        if(0>nx||nx>N-1||0>ny||ny>M-1) continue;
                        if(check[nx][ny]||A[nx][ny]==0) continue;
                        check[nx][ny] = true;
                        A[nx][ny] = n;
                        q.push({nx,ny});
                    }
                }
            }
        }
    }
}

void getDistance(int u, int v){ //u번 섬에서 v번 섬으로 가는 직선 최단 거리를 구한다.
    queue <pair<int,int>> q;
    
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(A[i][j] == u){ //u번 섬에 있는 칸들을 모두 큐에 넣는다.
                q.push({i,j}); 
            }
        }
    }
    
    int minDist = INT_MAX;
    
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        for(int d=0; d<4; d++){
            int nx = x + dx[d];
            int ny = y + dy[d];
            int dist = 0;
            
            while(true){  //한방향으로 계속 이동
                if(0>nx||nx>N-1||0>ny||ny>M-1) break; //범위를 넘어간 경우
                if(A[nx][ny]==u) break; //같은 섬인경우 더 탐색하지 않는다.
                
                if(A[nx][ny]==v){  //v번섬인 경우 최소거리와 비교후 더 탐색하지 않는다.
                    if(dist>1 && minDist>dist) minDist = dist; 
                    break;
                }
                else if(A[nx][ny]==0){ //바다인 경우 거리증가하고 이동
                    dist++;
                    nx += dx[d];
                    ny += dy[d];
                }
                else break;  //다른 섬인 경우 더 탐색하지 않는다.
            }
        }
    }
    
    if(minDist!=INT_MAX) vt.push_back({minDist,{u,v}}); //최소거리가 초기값이 아니라면 벡터에 최소거리와 섬의 번호를 넣는다.
}

int getParent(int x){
    if(p[x]==x) return x;
    return p[x]=getParent(p[x]);
}

void unionSet(int a, int b){
    a = getParent(a);
    b = getParent(b);
    p[a] = b;
}

int main() {
    scanf("%d %d", &N, &M);
    
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            scanf("%d", &A[i][j]);
        }
    }
    
    getIndex();
    
    for(int i=1; i<=n-1; i++){
        for(int j=i+1; j<=n; j++){
            getDistance(i,j); //각 섬들간의 만들수 있는 다리를 모두 만든다.
        }
    }
    
    int size = vt.size();
    
    sort(vt.begin(), vt.end()); //거리를 기준으로 오름차순 정렬
    
    for(int i=1; i<=n; i++) p[i] = i; //부모 배열 초기화(처음 부모는 자기 자신)
    
    int sum=0, index=0, cnt=0;
    int u,v,dist;
    
    while(cnt<n-1){  //선택한 간선의 개수가 섬의개수 -1이 될때까지 간선을 선택한다.
        if(index==size){  //모든 섬을 연결하는 것이 불가능하다
            sum = -1;
            break;
        }
        
        dist = vt[index].first;
        u = vt[index].second.first;
        v = vt[index].second.second;
        index++;
        
        if(getParent(u)==getParent(v)) continue;  //이미 연결되어 있다.
        else {
            unionSet(u,v); //연결되어 있지 않다면 합친다.
            cnt++; //연결된 간선의 수 증가
            sum += dist; //다리 길이에 합쳐준다.
        }
    }
    printf("%d", sum);
    return 0;
}
