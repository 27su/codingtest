// 백준 : https://www.acmicpc.net/problem/19236
// 참고 : https://yabmoons.tistory.com/495

#include <bits/stdc++.h>
using namespace std;

struct Fish{
    int x,y,dir;
    bool live;
};

int result;
int arr[4][4];
Fish fish[20];

int dx[] = { 0, -1, -1, 0, 1, 1, 1, 0, -1 };  
int dy[] = { 0, 0, -1, -1, -1, 0, 1, 1, 1 };
//d+1할때마다 45도 방향으로

void swap_fish(int a, int b){ //물고기 좌표 바꿔주기
    Fish temp = fish[a];
    fish[a].x = fish[b].x;
    fish[a].y = fish[b].y;
    fish[b].x = temp.x;
    fish[b].y = temp.y;
}

void moveFish(){
    for(int i=1; i<=16; i++){ //작은 물고기부터 이동
        if(fish[i].live==false) continue; 
        
        int x = fish[i].x;
        int y = fish[i].y;
        int d = fish[i].dir;
        
        int nx = x + dx[d];
        int ny = y + dy[d];
        
        bool flag = false;
        
         if (nx >= 0 && ny >= 0 && nx < 4 && ny < 4){ //원래 방향으로 이동 가능한지 체크
            if(arr[nx][ny]==0){
                flag = true;
                fish[i].x = nx;
                fish[i].y = ny;
                arr[nx][ny] = i;
                arr[x][y] = 0;
            }
            else if(arr[nx][ny]!=-1){
                flag = true;
                swap_fish(i,arr[nx][ny]);
                swap(arr[x][y], arr[nx][ny]);
            }
        }
        
        
        if(!flag){ //이동 불가능이면 방향 바꿔서 탐색
            int nextDir = d+1; //45도 방향으로 바꾸기
            if(nextDir==9) nextDir=1;
            
            nx = x+dx[nextDir];
            ny = y+dy[nextDir];
            
            while(nextDir != d){ //모든 방향 탐색
                if (nx >= 0 && ny >= 0 && nx < 4 && ny < 4){
                    if(arr[nx][ny]==0){
                        fish[i].x = nx;
                        fish[i].y = ny;
                        arr[nx][ny] = i;
                        arr[x][y] = 0;
                        fish[i].dir = nextDir;
                        break;
                    }
                    else if(arr[nx][ny]!=-1){
                        swap_fish(i,arr[nx][ny]);
                        swap(arr[x][y], arr[nx][ny]);
                        fish[i].dir = nextDir;
                        break;
                    }
                }
                nextDir++;
                if(nextDir==9) nextDir=1;
                
                nx = x+dx[nextDir];
                ny = y+dy[nextDir];
            }
        }
    }
}

void dfs(int x, int y, int dir, int sum){
    
    result = max(result, sum); //최대값 갱신
    int temp_arr[4][4];
    Fish temp_fish[20];
    for(int i=0; i<4; i++) for(int j=0; j<4; j++) temp_arr[i][j] = arr[i][j];
    for(int i=0; i<=16; i++) temp_fish[i] = fish[i];
    
    moveFish(); //물고기 이동
    
    for(int i=1; i<=3; i++){ //상어 이동 
        int nx = x + dx[dir]*i;
        int ny = y + dy[dir]*i;
        if(0>nx||nx>3||0>ny||ny>3) break;
        if(arr[nx][ny]==0) continue;
        
        int fish_n = arr[nx][ny];
        int nextDir = fish[fish_n].dir;
        
        arr[x][y] = 0;
        arr[nx][ny] = -1;
        fish[fish_n].live = false;
      
        dfs(nx,ny,nextDir, sum+fish_n);
        
        arr[x][y] = -1;
        arr[nx][ny] = fish_n;
        fish[fish_n].live = true;
    }
    
    for(int i=0; i<4; i++) for(int j=0; j<4; j++) arr[i][j] = temp_arr[i][j];
    for(int i=0; i<=16; i++) fish[i] = temp_fish[i];
}

int main() {
    
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            int a, b;
            scanf("%d %d", &a, &b);
            arr[i][j] = a;
            fish[a] = {i, j, b, true};
        }
    }
    
    int startN = arr[0][0];
    int startD = fish[startN].dir;
    fish[startN].live = false;
    arr[0][0] = -1;
    
    dfs(0,0,startD, startN);
    printf("%d", result);
    return 0;
}