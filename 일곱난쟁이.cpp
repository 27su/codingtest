// 백준 : https://www.acmicpc.net/problem/2309

#include <bits/stdc++.h>

using namespace std;

bool flag = false;
vector <int> result;
vector <int> v;
bool check[10]={0, };

void getResult(int index, int sum){
    if(flag) return;
    if(index == 7){
        if(sum == 100){
            for(int i=0; i<7; i++) printf("%d\n", result[i]);
            flag = true;
        }
        return;
    }
    else if(sum >= 100) return;
    
    for(int i=0; i<9; i++){
        if(check[i]) continue;
        check[i] = true;
        result.push_back(v[i]);
        getResult(index+1, sum+v[i]);
        result.pop_back();
        check[i] = false;
    }
}

int main() {
    for(int i=0; i<9; i++){
        int temp;
        scanf("%d", &temp);
        v.push_back(temp);
    }
    
    sort(v.begin(), v.end());
    getResult(0,0);
    return 0;
}