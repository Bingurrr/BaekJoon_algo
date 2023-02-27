#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>
#include <bitset>
#include <set>
#include <vector>
#include <string>
#include <cstring>
#include <map>
#include <stack>


using namespace std;

int n;
int arr[1001];
int dp1[1001];
int dp2[1001];
int m1, m2, ans;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);	

    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    dp1[0] = 1;
    for(int i = 0; i < n; i++){
        dp1[i] = 1;
        for(int j = 0; j < i; j++){
            if(arr[j] < arr[i] && dp1[i] < dp1[j]+1){
                dp1[i] = dp1[j] + 1;
            }
        }
    }

    for(int i = n-1; i >= 0; i--){
        dp2[i] = 1;
        for(int j = n-1; j > i; j--){
            if(arr[j] < arr[i] && dp2[i] < dp2[j]+1){
                dp2[i] = dp2[j] + 1;
            }
        }
    }

    for(int i = 0; i < n; i++){
        if(dp1[i] + dp2[i] > ans) ans = dp1[i] + dp2[i];
    }
    cout << ans-1;

	return 0; 
}