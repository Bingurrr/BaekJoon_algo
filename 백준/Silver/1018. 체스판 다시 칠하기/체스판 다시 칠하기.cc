#include <iostream>
#include <cmath>
#include <algorithm>
#define MAX 51

using namespace std;

int n,m;
char arr[MAX][MAX];
int ans = 64;
int cnt;
int cnt1, cnt2;

void solve(int a, int b){
    //시작이 W로 시작
    for(int i = a; i < a+8; i++){
        for(int j = b; j < b + 8; j++){
            if(i%2 ==0){
                if(j%2==0 && arr[i][j] == 'B') cnt1++;
                if(j%2==1 && arr[i][j] == 'W') cnt1++;
            }
            else{
                if(j%2==1 && arr[i][j] == 'B') cnt1++;
                if(j%2==0 && arr[i][j] == 'W') cnt1++;
            }
        }
    }
    //시작이 B로 시작
    for(int i = a; i < a+8; i++){
        for(int j = b; j < b + 8; j++){
            if(i%2 ==0){
                if(j%2==0 && arr[i][j] == 'W') cnt2++;
                if(j%2==1 && arr[i][j] == 'B') cnt2++;
            }
            else{
                if(j%2==1 && arr[i][j] == 'W') cnt2++;
                if(j%2==0 && arr[i][j] == 'B') cnt2++;
            }
        }
    }
    if(cnt1 > cnt2) cnt = cnt2;
    else cnt = cnt1;
    // cout << cnt1 << " " << cnt2 << endl; 
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    for(int i = 0; i < n; i ++){
        for(int j = 0; j < m; j++){
            cin >> arr[i][j];
        }
    }
    for(int i = 0; i <= n-8; i++){
        for(int j = 0; j <= m-8; j++){
            solve(i,j);
            if(ans > cnt) ans = cnt;
            cnt = 0;
            cnt1 = 0;
            cnt2 = 0;
        }
    }
    
    cout << ans;
}