#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>
#include <bitset>
#include <set>
#include <vector>
#include <cstring>
#include <set>
#define INF 1000002

using namespace std;

int a,b,c,k;
int dp[INF];
int arr[6][2];
bool visited[INF];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> a >> b >> c >> k;

    // (a,b), (c,c), (aac). (bbc) -> 한바퀴 돔
    // 위 4개의 방법으로 결국 k까지 에너지를 사용해야함
    
    arr[0][0] = a+b;
    arr[0][1] = 2;
    arr[1][0] = c+c;
    arr[1][1] = 2;
    arr[2][0] = a+a+c;
    arr[2][1] = 3;
    arr[3][0] = b+b+c;
    arr[3][1] = 3;
    arr[4][0] = a*4;
    arr[4][1] = 4;
    arr[5][0] = b*4;
    arr[5][1] = 4;

    visited[0] = 1;
    
    for(int i = 1; i<= k; i++){
        dp[i] = INF;
        for(int j = 0; j < 6; j++){
            //visited == 0 이면 한바퀴 안돌았다는 거임
            if(i - arr[j][0]>= 0 && visited[i-arr[j][0]] == 1){
                visited[i] = true;
                dp[i] = min(dp[i], dp[i-arr[j][0]]+arr[j][1]);
            }
        }
    }
    
    if(visited[k] == 0) dp[k] = -1;
    cout << dp[k];
	return 0; 
}
