#include <bits/stdc++.h>

using namespace std;

bool cmp(pair<int, double> a, pair<int, double> b){
    if (a.second < b.second) return false;
    else if (a.second == b.second) {
        if (a.first < b.first) return true;
        else return false;
    }
    else return true;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<pair<int, double>> rate;
    
    sort(stages.begin(),stages.end());
    
    int total = stages.size();
    int max_stage = stages[stages.size()-1];
    
    for(int i=1; i<=N; i++){
        if(i > max_stage){
            rate.push_back({i, 0});
            continue;
        }
        
        double cnt = 0;
        for(int j=0; j<stages.size(); j++){
            if(i==stages[j]){
                cnt++;
            } 
        }
        rate.push_back({i, cnt/(double)total});
        total -= cnt;
    }
    
    sort(rate.begin(), rate.end(), cmp);
    for(int i=0; i<rate.size(); i++) answer.push_back(rate[i].first);
    return answer;
}
