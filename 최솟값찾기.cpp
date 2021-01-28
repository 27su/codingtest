// 백준 : https://www.acmicpc.net/problem/11003

#include <bits/stdc++.h>
using namespace std;

int main() {
    int N,L;
    scanf("%d %d", &N, &L);
    
    deque <pair<int,int>> dq;
    
    for(int i=0; i<N; i++){
        int value;
        scanf("%d", &value);
        while(!dq.empty() && dq.front().second <= i-L) dq.pop_front(); //L개만 저장
        while(!dq.empty() && dq.back().first >= value) dq.pop_back(); //dq안에서 value가 가장 큼
        dq.push_back({value, i});
        printf("%d ", dq.front().first);
    }
    
    return 0;
}
