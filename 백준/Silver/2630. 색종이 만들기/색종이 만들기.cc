#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>
#include <bitset>
#include <set>
#include <vector>

using namespace std;

int n;
int arr[129][129];
int ans[2];

void solve(int a, int b, int gap){
    int k = arr[a][b];
    if(gap<=1){
        ans[k]++;
        return;
    }
    for(int i = a; i < a+gap; i++){
        for(int j = b; j < b+gap; j++){
            if(arr[i][j] != k) {
                solve(a,b,gap/2);
                solve(a+gap/2,b,gap/2);
                solve(a,b+gap/2,gap/2);
                solve(a+gap/2, b+gap/2, gap/2);
                return;
            }
        }
    }
    ans[k]++;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);	
	cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> arr[i][j];
        }
    }
    solve(0,0,n);
    cout << ans[0] << '\n' << ans[1];
	return 0; 
}