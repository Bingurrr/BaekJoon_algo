#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

int n;
int ans;

int arr[100001];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    n--;
    for(int i = 0; i < 1000000000; i++){
        if((i+1)*i/2 * 6 >= n){
            ans = i+1;
            break;
        }
    }
    cout << ans;
    return 0;
}