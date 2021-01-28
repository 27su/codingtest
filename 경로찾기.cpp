// 백준 : https://www.acmicpc.net/problem/11403

#include <bits/stdc++.h>
using namespace std;

vector <int> g[105];
int N;

void BFS(int start){
    queue <int> q;
    bool check[105] = {0, };
    q.push(start);
    
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for(int i=0; i<(int)g[cur].size(); i++){
            int next = g[cur][i];
            if(check[next]) continue;
            q.push(next);
            check[next] = true;
        }
    }
    
    for(int i=0; i<N; i++){
        if(check[i]) printf("1 ");
        else printf("0 ");
    }
}
int main() {
    
    scanf("%d", &N);
    
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            int temp;
            scanf("%d", &temp);
            if(temp==1) g[i].push_back(j);
        }
    }
    
    
    for(int i=0; i<N; i++){
        BFS(i);
        printf("\n");
    }
    
    return 0;
}
