// 백준 : https://www.acmicpc.net/problem/19238

#include <bits/stdc++.h>
using namespace std;

struct Custom{
    int x, y, s, e;
    bool success;
};


int N, M, E;
int arr[30][30];
vector <Custom> custom;
int x,y;

int dx[]={0,0,1,-1}, dy[]={1,-1,0,0};

bool end(){
    for(int i=0; i<custom.size(); i++){
        if(!custom[i].success) return false;
    }
    return true;
}

int getDistance(int ex, int ey){
    queue <pair<int,int>> q;
    bool check[30][30]={0,0};
    
    q.push({x,y});
    check[x][y] = true;
    
    int d[30][30];
    memset(d,-1,sizeof(d));
    
    d[x][y] = 0;
    
    while(!q.empty()){
        pair <int,int> cur = q.front();
        q.pop();
        if(cur.first == ex && cur.second == ey) return d[cur.first][cur.second];
        for(int i=0; i<4; i++){
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
            
            if(1>nx||nx>N||1>ny||ny>N) continue;
            if(check[nx][ny] || arr[nx][ny]) continue;
            q.push({nx,ny});
            check[nx][ny] = true;
            d[nx][ny] = d[cur.first][cur.second] + 1;
        }
    }
    
    return d[ex][ey];
}

pair<int, int> getIndex(){
    int result=-1;
    int distance=INT_MAX;
    for(int i=0; i<custom.size(); i++){
        if(custom[i].success) continue;
        int d = getDistance(custom[i].x, custom[i].y);
        if(d == -1) continue;
        if(d<distance){
            result = i;
            distance = d;
        }
        else if(d == distance){
            if(custom[result].x>custom[i].x){
                result = i;
                distance = d;
            }
            else if(custom[result].x == custom[i].x){
                if(custom[result].y>custom[i].y){
                    result = i;
                    distance = d;
                }
            }
        }
    }
    
    return {result, distance};
}

bool move(pair<int,int> next){
    int d = next.second;
    int index = next.first;
    
    if(d>E) return false;
    
    x = custom[index].x;
    y = custom[index].y;
    E -= d;
    
    int end = getDistance(custom[index].s, custom[index].e);
    if(end == -1 || end > E) return false;
    x = custom[index].s;
    y = custom[index].e;
    E = E - end + end*2;
    custom[index].success = true;
    return true;
}

int main() {
    scanf("%d %d %d", &N, &M, &E);
    
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            scanf("%d", &arr[i][j]);            
        }
    }
    
    
    scanf("%d %d", &x, &y);
    
    for(int i=0; i<M; i++){
        int a,b,c,d;
        scanf("%d %d %d %d", &a, &b, &c, &d);
        custom.push_back({a,b,c,d, false});
    }
    
    while(!end()){
        pair<int,int> next = getIndex();
        if(next.first == -1){
            E = -1;
            break;
        } 
        else if(!move(next)){
            E = -1;
            break;
        }
    }
    
    printf("%d", E);
    return 0;
}
