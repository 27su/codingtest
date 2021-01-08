//프로그래머스 : https://programmers.co.kr/learn/courses/30/lessons/62050

#include <bits/stdc++.h>

using namespace std;

int m[500][500];
int group[500][500]={0, };
int answer = 0;
int cnt_g=0;
int lenx, leny;

int dx[]={0,0,1,-1}, dy[]={1,-1,0,0};

vector<int> Parent;
vector<pair<int, pair<int, int>>> Edge;


void setGroup(int x, int y, int height){
    cnt_g++;
    queue <pair<int,int>> q;
    bool check[500][500]={0, };
    q.push({x,y});
    check[x][y] = true;
    group[x][y] = cnt_g;
    
    while(!q.empty()){
        pair<int,int> cur = q.front();
        q.pop();
        
        for(int d=0; d<4; d++){
            int nx = cur.first+dx[d];
            int ny = cur.second+dy[d];
            if(0>nx||nx>lenx-1||0>ny||ny>leny-1) continue;
            if(check[nx][ny]||group[nx][ny]!=0) continue;
            if(abs(m[cur.first][cur.second]-m[nx][ny])>height) continue;
            group[nx][ny] = cnt_g;
            check[nx][ny] = true;
            q.push({nx,ny});
        }
    }
}

void getGroupDistance(){
    for(int i=0; i<lenx; i++){
        for(int j=0; j<leny; j++){
            for(int d=0; d<4; d++){
                int nx = i+dx[d];
                int ny = j+dy[d];
                if(0>nx||nx>lenx-1||0>ny||ny>leny-1) continue;
                if(group[i][j]==group[nx][ny]) continue;
                int temp = abs(m[i][j]-m[nx][ny]);
                Edge.push_back({temp,{group[i][j], group[nx][ny]}});
            }
        }
    }
}

int Find_Parent(int A)
{
    if (A == Parent[A]) return A;
    return Parent[A] = Find_Parent(Parent[A]);
}
 
void Union(int A, int B)
{
    A = Find_Parent(A);
    B = Find_Parent(B);
    Parent[B] = A;
}

void Kruskal(){
    Parent.resize(cnt_g+1);
    sort(Edge.begin(), Edge.end());
    for (int i = 1; i <= cnt_g; i++) Parent[i] = i;
    for (int i = 0; i < Edge.size(); i++)
    {
        int N1 = Edge[i].second.first;
        int N2 = Edge[i].second.second;
        int Cost = Edge[i].first;
        
        if(Find_Parent(N1) != Find_Parent(N2))
        { 
            Union(N1, N2);
            answer += Cost;
        }
    }
}

int solution(vector<vector<int>> land, int height) {
    lenx = land.size();
    leny = land[0].size();
    
    for(int i=0; i<lenx; i++) for(int j=0; j<leny; j++) m[i][j]=land[i][j];
    
    for(int i=0; i<lenx; i++){
        for(int j=0; j<leny; j++){
            if(group[i][j]==0){
                setGroup(i,j,height);
            }
        }
    }
    
    getGroupDistance();
    Kruskal();
    
    return answer;
}