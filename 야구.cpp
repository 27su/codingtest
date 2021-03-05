//백준 : https://www.acmicpc.net/problem/17281

#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    scanf("%d", &N);
    vector <vector<int>> score(N+1, vector(10,0));
    for(int i=0; i<N; i++){
        for(int j=0; j<9; j++){
            scanf("%d", &score[i][j]);
        }
    }
    
    vector <int> v;
    for(int i=0; i<9; i++) v.push_back(i);
    
    int result = 0;
    do{
        if(v[3]!=0) continue;
        
        int cur = 0, grade=0;
        for(int k=0; k<N; k++){
            int out = 0;
            bool base[4]={0,0,0,0};
            while(out<3){
                base[0] = true;
                if(score[k][v[cur]]==0) { //아웃
                    out++;
                }
                else{
                    for(int i=3; i>=0; i--){
                        if(!base[i]) continue;
                        int index = i + score[k][v[cur]];
                        if(index>3) grade++;
                        else base[index] = true;
                        base[i] = false;
                    }
                }
                cur = (cur+1)%9;
            }
        }
        result = max(result, grade);
        
    }while(next_permutation(v.begin(), v.end()));
    
    printf("%d", result);
    return 0;
}
