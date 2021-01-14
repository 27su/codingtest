// 백준 : https://www.acmicpc.net/problem/15666
#include <bits/stdc++.h>

using namespace std;

vector <int> result;
int N,M;
vector <int> arr;

void getResult(int index, int start){
    if(index==M){
        for(int i=0; i<M; i++) printf("%d ", result[i]);
        printf("\n");
        return;
    }
    
    int before = -1;
    for(int i=start; i<(int)arr.size(); i++){
        if(arr[i] == before) continue;
        result.push_back(arr[i]);
        getResult(index+1, i);
        result.pop_back();
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
    getResult(0,0);
    return 0;
}