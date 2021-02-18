// 프로그래머스 : https://programmers.co.kr/learn/courses/30/lessons/60062

#include <bits/stdc++.h>
using namespace std;

int solution(int n, vector<int> weak, vector<int> dist) {
    int answer = INT_MAX;
    int len = weak.size();
    
    for(size_t i = 0; i < len - 1; i++)
        weak.emplace_back(weak[i] + n);
    
    do{
        for(int i = 0; i < len; i++){
            int idx = 0; //친구 인덱스
            bool flag = true; //전체 가능한지
            int end = weak[i] + dist[idx]; //idx친구가 갈수있는 최대 지점
            
            for(int j = i + 1; j < i + len; j++){
                if(end < weak[j]){ //도달 못하면
                    if(idx + 1 == dist.size()) {  //친구 더 없으면 실패 
                        flag = false;
                        break;
                    }
                    else end = weak[j] + dist[++idx]; // 다른친구 추가   
                }
            }
            if(flag) answer = min(answer, idx + 1);  
        }
    }while(next_permutation(dist.begin(), dist.end()));
    
    if(answer==INT_MAX) answer = -1;
    return answer;
}
