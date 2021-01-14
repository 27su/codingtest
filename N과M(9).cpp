// 백준 : https://www.acmicpc.net/problem/15663

#include <bits/stdc++.h>
using namespace std;

vector <int> result;
int N,M;
vector <bool> check;
vector <int> arr;

void getResult(int index){
    if(index==M){
        for(int i=0; i<M; i++) printf("%d ", result[i]);
        printf("\n");
        return;
    }
    
    int before = -1;
    for(int i=0; i<(int)arr.size(); i++){
        if(check[i] || arr[i] == before) continue;
        check[i] = true;
        result.push_back(arr[i]);
        getResult(index+1);
        result.pop_back();
        check[i] = false;
        before = arr[i];
    }
}

int main() {
    scanf("%d %d", &N, &M);
    for(int i=0; i<N; i++){
        int temp;
        scanf("%d", &temp);
        arr.push_back(temp);
    }
    sort(arr.begin(), arr.end());
    check.assign(N+1,0);
    getResult(0);
    return 0;
}