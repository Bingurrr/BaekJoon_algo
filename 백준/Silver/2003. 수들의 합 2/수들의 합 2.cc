#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>
#include <bitset>
#include <set>
#include <vector>
#include <cstring>
using namespace std;

int n, m;
int arr[10001];

int solve(){
    int cnt = 0;
    int start = 0, end = 0;
    int sum = 0;
    while(true){
        if(sum >= m){
            sum = sum - arr[start++]; 
        }else if(end == n){
            break;
        }else{
            sum = sum + arr[end++];
        }
        if(sum == m){
            cnt++;
        }
    }
    return cnt;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for(int i =0; i < n; i++){
        cin >> arr[i];
    }
    cout << solve() << endl;
	return 0; 
}
