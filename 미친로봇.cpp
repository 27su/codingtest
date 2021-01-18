//백준 : https://www.acmicpc.net/problem/1405

#include<bits/stdc++.h>
using namespace std;
 
int n;
bool arr[100][100];
double d[4];
double ret;
 
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };
 
void dfs(int y, int x, int cnt, double p) {
    if (cnt == n) {
        ret += p;
        return;
    }
 
    int ny, nx;
    for (int i = 0; i < 4; i++) {
        ny = y + dy[i];
        nx = x + dx[i];
        if(arr[ny][nx]) continue;
        arr[ny][nx] = true;
        dfs(ny, nx, cnt + 1, p * d[i]);
        arr[ny][nx] = false;
    }
}
 
 
int main(){
    scanf("%d", &n);
    for (int i = 0; i < 4; i++) {
        scanf("%lf", &d[i]);
        d[i] /= 100;
    }
 
 
    arr[50][50] = 1;
    dfs(50,50,0,1);
 
    cout.precision(11);
    cout.fixed;
    
    cout << ret << "\n";
    
 
    return 0;
}