// 백준 : https://www.acmicpc.net/problem/1707
// 참고 : https://gmlwjd9405.github.io/2018/08/23/algorithm-bipartite-graph.html

#include <bits/stdc++.h>
using namespace std;

int K, V, E;
vector <int> g[20005];
int check[20005]={0, };
bool flag = true;

void BFS(int x){
    queue <int> q;
    q.push(x);
    check[x] = 1;
    
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        
        for(int i=0; i<(int)g[cur].size(); i++){
            int next = g[cur][i];
            if(check[next]==check[cur]){
                flag = false;
                return;
            } 
            if(check[next]==0){
                q.push(next);
                check[next] = check[cur]*-1;
            }
        }
    }
}



int main() {
    scanf("%d", &K);
    
    for(int k=0; k<K; k++){
        flag = true;
        scanf("%d %d", &V, &E);
        
        for(int i=0; i<E; i++){
            int a,b;
            scanf("%d %d", &a, &b);
            g[a].push_back(b);
            g[b].push_back(a);
        }

        for(int i=1; i<=V; i++){
            if(check[i]==0) BFS(i);
            if(!flag) break;
        }
        
        if(flag) printf("YES");
        else printf("NO");
        printf("\n");
        
        for(int i=1; i<=V; i++) {g[i].clear(); check[i]=0;}
    }
    
    
    
    return 0;
}