// 백준 : https://www.acmicpc.net/submit/14003
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,cnt=0;
    vector <int> ans, print, arr, p;
    //arr : 원래 데이터
    //ans : 가장 긴 증가하는 부분 수열을 구성하는 데이터
    //p[i] : arr[i]가 들어간 ans 인덱스를 저장
    //print : 가장 긴 증가하는 부분 수열
    scanf("%d", &n);
    
    arr.resize(n+1,0);
    p.resize(n+1,0);
    
    for(int i = 1; i <= n; i++) scanf("%d", &arr[i]);
    ans.push_back(arr[1]);
    
    for(int i = 2; i <= n; i++){
        if(ans[cnt] < arr[i]){ //클경우에는 그냥 뒤에 넣어주고 인덱스 증가시킨 다음
            ans.push_back(arr[i]), cnt++;
            p[i] = cnt; //현재 원소가 들어간 인덱스를 p에 저장
        }
        else{ //같거나 작을경우
            int pos = lower_bound(ans.begin(), ans.end(), arr[i]) - ans.begin(); //arr[i]가 ans중 어느 원소의 값을 대처할 수 있는지 lower_boun를 이용해 찾는다
            ans[pos] = arr[i]; //찾은자리에 arr[i] 저장
            p[i] = pos; //현재 원소가 들어간 인덱스를 p에 저장
        } 
    }

    printf("%d\n", cnt + 1);
    for(int i = n; i >= 1 && cnt >= 0; i--){
        if(p[i] == cnt){
            print.push_back(arr[i]);
            cnt--;
        }
    }
    for(int i = print.size() - 1; i >= 0; i--){
        printf("%d ", print[i]);
    }
    return 0;
}