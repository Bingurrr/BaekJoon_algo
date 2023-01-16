#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>
#include <bitset>
#include <set>
#include <vector>
using namespace std;

int n, m;
int ans = 1;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;

    for(int i = 2; i <=n; i++){
        ans = (ans+ m - 1) % i +1;
    }
    cout << ans;

    
    return 0;
}