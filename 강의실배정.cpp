//백준 : https://www.acmicpc.net/problem/11000
#include <bits/stdc++.h>
using namespace std;


int main() {
    int N;
    scanf("%d", &N);
    
    vector <pair<int,int>> v;
    for(int i=0; i<N; i++){
        int S,T;
        scanf("%d %d", &S, &T);
        v.push_back({S,T});
    }
    sort(v.begin(),v.end()); //시작시간을 기준으로 오름차순 정렬
    
    priority_queue<int, vector<int>, greater<int>>pq; //끝나는시간 오름차순 정렬
    pq.push(v[0].second); //우선순위 큐의 top에 있는 정보는 강의실들 중 가장 빨리 끝나는 강의의 시간
    
    for(int i=1; i<N; i++){
        if(pq.top()<=v[i].first) pq.pop(); //강의의 시작시간이 같거나 더 늦으면 이미 존재하는 강의실을 사용할 수 있으므로 pop
        pq.push(v[i].second);
    }
    
    printf("%d", pq.size());
    return 0;
}
