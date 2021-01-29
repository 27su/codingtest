//백준 : https://www.acmicpc.net/problem/19237

#include <bits/stdc++.h>
using namespace std;

//0,1,2,3, =  위, 아래, 왼쪽, 오른쪽

int dx[]={-1,1,0,0}, dy[]={0,0,-1,1};
int N, M, k;

struct Shark{
    int x;
    int y;
    int num;
    int dir;
    bool live;
};

Shark make(int x, int y, int num, int dir, bool live){
    Shark temp;
    temp.x = x;
    temp.y = y;
    temp.num = num;
    temp.dir = dir;
    temp. live = live;
    return temp;
}

int arr[25][25];
pair<int,int> info[25][25];
vector <Shark> shark;

struct Prior{
    vector <int> dir[4];
};

Prior make_P(vector <int> dir[4]){
    Prior temp;
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            temp.dir[i].push_back(dir[i][j]);
        }
    }
    return temp;
}

vector <Prior> shark_prior;

bool cmp(Shark a, Shark b){
    return a.num < b.num;
}

bool end(){
    int cnt=0;
    for(int i=0; i<(int)shark.size(); i++){
        if(shark[i].live) cnt++;
    }
    
    if(cnt!=1) return false;
    else return true;
}

void move(){
    pair<int,int> temp[25][25];
    for(int i=0; i<(int)shark.size(); i++){
        if(!shark[i].live) continue;
        Shark cur = shark[i];
        bool flag = false;
        
        for(int d=0; d<4; d++){
            if(flag) break;
            int dir = shark_prior[i].dir[cur.dir][d];
            
            int nx = cur.x + dx[dir];
            int ny = cur.y + dy[dir];
            
            if(0>nx||nx>N-1||0>ny||ny>N-1) continue;
            if(info[nx][ny].second!=0) continue;
            if(temp[nx][ny].second!=0){
                shark[i].live = false;
                flag = true;
                break;
            }
            flag = true;
            shark[i].x = nx;
            shark[i].y = ny;
            shark[i].dir = dir;
            temp[nx][ny].first = cur.num;
            temp[nx][ny].second = k;
        }
        if(!flag){
            for(int d=0; d<4; d++){
                int dir = shark_prior[i].dir[cur.dir][d];
                
                int nx = cur.x + dx[dir];
                int ny = cur.y + dy[dir];
                
                if(0>nx||nx>N-1||0>ny||ny>N-1) continue;
                if(info[nx][ny].first == cur.num){
                    flag = true;
                    shark[i].x = nx;
                    shark[i].y = ny;
                    shark[i].dir = dir;
                    temp[nx][ny].first = cur.num;
                    temp[nx][ny].second = k;
                    break;
                }
            }
        }
        
    }
    
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(info[i][j].second==0) continue;
            info[i][j].second--;
            if(info[i][j].second==0) info[i][j].first = 0;
        }
    }
    
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(temp[i][j].second==0) continue;
            info[i][j] = temp[i][j];
        }
    }
}


int main(){
    
    scanf("%d %d %d", &N, &M, &k);
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            scanf("%d", &arr[i][j]);
            if(arr[i][j]!=0) {
                shark.push_back(make(i,j,arr[i][j],0,true));
                info[i][j] = {arr[i][j], k};
            }
            else info[i][j] = {0,0};
        }
    }
    sort(shark.begin(), shark.end(), cmp);
    for(int i=0; i<(int)shark.size(); i++){
        int dir;
        scanf("%d", &dir);
        shark[i].dir = dir-1;
    }
    
    for(int i=0; i<(int)shark.size(); i++){
        vector<int> temp[4];
        for(int j=0; j<4; j++){
            for(int d=0; d<4; d++){
                int dir;
                scanf("%d", &dir);
                temp[j].push_back(dir-1);
            }
        }
        shark_prior.push_back(make_P(temp));
    }
    
    int result=0;
    while(!end()&&result<=1000){
        move();
        result++;
    }
    
    if(result>1000) result = -1;
    printf("%d", result);
    return 0;
}
