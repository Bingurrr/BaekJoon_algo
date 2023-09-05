#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>
#include <bitset>
#include <set>
#include <vector>
#include <cstring>
#include <set>
#include <stack>
#include <regex>
#define INF (1 << 30)

using namespace std;

int n;
int arr[21][21];
int ans = 9999999;
int sum = 0;
int visited[22];
// 조합 10C5


void sol(int k, int p){
    if(k == n/2){
        int s = 0;
        int l = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(visited[i] == 1 && visited[j] == 1){
                    s += arr[i][j];
                }
                else if(visited[i] == 0 && visited[j] == 0) l += arr[i][j];
            }
        }
        if(ans > abs(l-s)) ans = abs(l-s);
        // cout << s << endl;
        return;
    }
    for(int i = p; i < n; i++){
        visited[i] = 1;
        sol(k+1, i+1);
        visited[i] = 0;
    }
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> arr[i][j];
            sum += arr[i][j];
        }
    }

    sol(0,0);
    cout << ans;
    
    return 0;
}


