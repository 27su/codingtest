//프로그래머스 : https://programmers.co.kr/learn/courses/30/lessons/72413

#include <bits/stdc++.h>
using namespace std;

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = 0;
    vector <vector<int>> adj(n+1,vector<int>(n+1,0));
    
    // 플로이드를 위해 충분히 큰 값으로 초기화
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			adj[i][j]=10000000;

	for(int i=1;i<=n;i++) adj[i][i]=0;

	for(auto v:fares){
		adj[v[0]][v[1]]=v[2];
		adj[v[1]][v[0]]=v[2];
	}

    // 플로이드 와샬
	for(int i=1;i<=n;i++) //거쳐가는 지점
		for(int j=1;j<=n;j++) //출발지점
			for(int k=1;k<=n;k++) //도착지점
				adj[j][k]=min(adj[j][k],adj[j][i]+adj[i][k]);

    // 충분히 큰 값으로 초기화
	answer = INT_MAX;

    // 브루트 포스
	for(int i=1;i<=n;i++)
		answer=min(answer,adj[s][i]+adj[i][a]+adj[i][b]);
	
  return answer;
}
