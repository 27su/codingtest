#include <bits/stdc++.h>

using namespace std;

bool cmp(pair<int,int> a, pair<int,int> b){
    return a.second < b.second;
}

int main() {
    int N;
    scanf("%d", &N);
    vector <pair<int,int>> P;
    for(int i=1; i<=N; i++){
        int temp;
        scanf("%d", &temp);
        P.push_back({i,temp});
    }
    sort(P.begin(), P.end(), cmp);
    
    int result = 0, sum=0;
    for(int i=0; i<N; i++){
        sum += P[i].second;
        result += sum;
    }
    printf("%d\n", result);
    return 0;
}

//백준 :https://www.acmicpc.net/problem/11399
