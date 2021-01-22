// 백준 : https://www.acmicpc.net/problem/6603

#include <bits/stdc++.h>
using namespace std;

int k;
vector <int> s;
vector <int> result;
vector <bool> check;

void getResult(int index, int start){
    if(index == 6){
        sort(result.begin(), result.end());
        for(int i=0; i<6; i++){
            printf("%d ", result[i]);
        }
        printf("\n");
        return;
    }
    
    for(int i=start; i<(int)s.size(); i++){
        if(check[i]) continue;
        check[i] = true;
        result.push_back(s[i]);
        getResult(index+1, i+1);
        result.pop_back();
        check[i] = false;
    }
}

int main() {
    while(true){
        /*string temp;
        getline(cin, temp);
        if(temp == "0") break;
        
        string num;
        stringstream ss(temp);
        
        int flag = false;
        while(getline(ss, num, ' ')) {
            if(flag) s.push_back(stoi(num));
            else {
                k = stoi(num);
                flag = true;
            }
        }*/
        int k;
        scanf("%d", &k);
        if(k == 0) break;
        
        for(int i=0; i<k; i++){
            int temp;
            scanf("%d", &temp);
            s.push_back(temp);
        }
        check.assign(s.size(), 0);
        getResult(0,0);
        printf("\n");
        
        s.clear();
    }
    
    return 0;
}