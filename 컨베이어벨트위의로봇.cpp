//백준 : https://www.acmicpc.net/problem/20055

#include <bits/stdc++.h>
using namespace std;
int N,K;
vector <pair<int, int>> A; 
int up = 0, down = 0;
vector <int> robot;

void rotate(){ //벨트가 한 칸 회전
    pair<int, int> e = A[2*N-1];
    for(int i=A.size()-2; i>=0; i--){
        A[i+1] = A[i];
    }
    A[0] = e;
    
    for(int i=0; i<(int)robot.size();){
        int next = robot[i]+1;
        if(next>2*N-1) next = 0;
        
        robot[i] = next;
        
        if(robot[i] == down){ //내려가는 위치에 로봇이 있는 경우 로봇은 반드시 땅으로 내려가야 한다.
            A[down].second = 0;
            robot.erase(robot.begin()+i);
        }
        else i++;
    }
    
}

void move(){
    for(int i=0; i<(int)robot.size();){
        int next = robot[i]+1;
        if(next>2*N-1) next = 0;
        
        if(A[next].first >= 1 && A[next].second == 0){
            A[next].first -= 1;
            A[next].second = 1;
            A[robot[i]].second = 0;
            robot[i] = next;
        }
        
        if(robot[i] == down){ //내려가는 위치에 로봇이 있는 경우 로봇은 반드시 땅으로 내려가야 한다.
            A[down].second = 0;
            robot.erase(robot.begin()+i);
        }
        else i++;
    }
}

bool end(){
    int cnt = 0;
    for(int i=0; i<(int)A.size(); i++){
        if(A[i].first==0) cnt++;
        if(cnt>=K) return true;
    }
    
    if(cnt>=K) return true;
    else return false;
}

int main() {
    scanf("%d %d", &N, &K);
    down = N-1;
    
    for(int i=0; i<2*N; i++){
        int temp;
        scanf("%d", &temp);
        A.push_back({temp,0});
    }
    
    int result = 0;
    while(!end()){
        result++;
        rotate();
        move();
        if(A[up].second == 0 && A[up].first >= 1){
            A[up].second = 1;
            A[up].first -= 1;
            robot.push_back(up);
        }
    }
 
    printf("%d", result);
    return 0;
}
