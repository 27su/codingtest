// 백준 : https://www.acmicpc.net/problem/17135

#include <bits/stdc++.h>
using namespace std;

int N,M,D;
int A[20][20], T[20][20];
int result=0, cnt=0;
bool check[20]={0, };
vector <pair<int,int>> v;
int dx[]={0,0,1,-1}, dy[]={1,-1,0,0};
vector <pair<int,int>> target, target_t;


void copy(){
    for(int i=0; i<N; i++) for(int j=0; j<M; j++) T[i][j] = A[i][j];
    for(int i=0; i<(int)target.size(); i++) target_t.push_back(target[i]);
}

bool cmp(pair<pair<int,int>,pair<int,int>> a, pair<pair<int,int>,pair<int,int>> b){
    if(a.second.first<b.second.first) return true;
    else if(a.second.first==b.second.first){
        if(a.first.second<b.first.second) return true;
    }
    return false;
}

void attack(){
    vector <pair<pair<int,int>,int>> r;
    for(int i=0; i<(int)v.size(); i++){
        
        vector <pair<pair<int,int>,pair<int,int>>> t;
        for(int j=0; j<target_t.size(); j++){
            int dist = abs(v[i].first-target_t[j].first)+abs(v[i].second-target_t[j].second);
            if(dist<=D) {t.push_back({target_t[j],{dist,j}});}
        }
        sort(t.begin(),t.end(), cmp);
        if(t.size()!=0) r.push_back({t[0].first,t[0].second.second});
    }
    for(int i=0; i<(int)r.size(); i++){
        if(T[r[i].first.first][r[i].first.second]){
            T[r[i].first.first][r[i].first.second]= 0;
            target_t.erase(target_t.begin()+r[i].second);
            cnt++;
        } 
    }
    
}

void move(){
    for(int i=N-2; i>=0; i--){
        for(int j=0; j<M; j++){
            T[i+1][j] = T[i][j];
        }
    }
    
    vector <int> temp;
    for(int i=0; i<(int)target_t.size(); i++){
        int nx = target_t[i].first+1;
        if(nx>N-1){
            temp.push_back(i);
        }
        else target_t[i].first += 1;
    }
    
    for(int i=0; i<(int)temp.size(); i++){
        target_t.erase(target_t.begin()+temp[i]);
    }
}

void getResult(int index){
    if(index==3){
        cnt = 0;
        copy();
        while(target_t.size()!=0){
            attack();
            move();
        }
        result = max(result,cnt);
        return;
    }
    
    for(int i=0; i<M; i++){
        if(check[i]) continue;
        check[i] = true;
        v.push_back({N,i});
        getResult(index+1);
        v.pop_back();
        check[i] = false;
    }
}

int main() {
    scanf("%d %d %d", &N,&M,&D);
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            scanf("%d", &A[i][j]);
            if(A[i][j]) target.push_back({i,j}); 
        }
    }
    
    getResult(0);
    printf("%d", result);
    return 0;
}
