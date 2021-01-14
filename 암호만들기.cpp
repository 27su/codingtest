// 백준 : https://www.acmicpc.net/problem/1759

#include <bits/stdc++.h>

using namespace std;

int L,C;
vector <char> arr;
vector <char> result;
vector <bool> check;

void getResult(int a, int b, int start){
    if(a+b==L){
        if(a>=1 && b >=2){
            for(int i=0; i<(int)result.size(); i++) printf("%c", result[i]);
            printf("\n");
        }
    }
    
    for(int i=start; i<C; i++){
        if(check[i]) continue;
        check[i] = true;
        result.push_back(arr[i]);
        if(arr[i]=='a'||arr[i]=='e'||arr[i]=='i'||arr[i]=='o'||arr[i]=='u') getResult(a+1,b,i+1);
        else getResult(a,b+1,i+1);
        result.pop_back();
        check[i] = false;
    }
    return;
}

int main() {
    scanf("%d %d", &L, &C);
    check.assign(C+1,0);
    for(int i=0; i<C; i++){
        char temp;
        scanf(" %c", &temp);
        arr.push_back(temp);
    }
    
    sort(arr.begin(), arr.end());
    getResult(0,0,0);
    return 0;
}