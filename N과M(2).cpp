//백준 : https://www.acmicpc.net/problem/15650

#include <bits/stdc++.h>

using namespace std;

vector <int> result;
vector <bool> check;
int N,M;

void getResult(int index, int start){
    if(index>=M){
        for(int i=0; i<M; i++) printf("%d ",result[i]);
        printf("\n");
        return;
    } 
    
    for(int i=start; i<=N; i++){
        if(check[i]) continue;
        result.push_back(i);
        check[i] = true;
        getResult(index+1, i+1);
        check[i] = false;
        result.pop_back();
    }
}

int main() {
    scanf("%d %d", &N, &M);
    check.resize(M+1);
    getResult(0, 1);
    return 0;
}