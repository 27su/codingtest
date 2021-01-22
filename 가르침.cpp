//백준 : https://www.acmicpc.net/problem/1062

#include <bits/stdc++.h>
using namespace std;

int N,K;
vector <string> word;
int result = 0;
bool check[30]={0, };

int getCnt(){
    int cnt = 0;
    for(int i=0; i<(int)word.size(); i++){
        bool flag = true;
        for(int j=0; j<(int)word[i].size(); j++){
            if(!check[word[i][j]-'a']){
                flag = false;
                break;
            }
        }
        if(flag) cnt++;
    }
    return cnt;
}

void dfs(int index, int start){
    if(index==K){
        result = max(result,getCnt());
        return;
    }
    
    for(int i=start; i<26; i++){
        if(check[i]) continue;
        check[i] = true;
        dfs(index+1, i+1);
        check[i] = false;
    }
}

int main() {
    scanf("%d %d", &N, &K);
    K-=5;
    
    for(int i=0; i<N; i++){
        string temp;
        cin >> temp;
        word.push_back(temp.substr(4, temp.size()-8));
    }
    
    if(K>=0){
        check[0] = true;
        check['n'-'a'] = true;
        check['t'-'a'] = true;
        check['i'-'a'] = true;
        check['c'-'a'] = true;
        dfs(0,0);
    }
    
    printf("%d", result);
    return 0;
}