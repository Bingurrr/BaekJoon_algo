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
#define endl "\n"
using namespace std;

int n, ans;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    while(cin >> n){
        if(n==0) break;
        ans = 1;
        while(n > 0){
            ans++;
            // cout << n << endl;
            // cout << n%10 << endl;
            if(n%10 == 1){
                ans += 2;
            }
            else if(n%10 == 0){
                ans += 4;
            }
            else ans += 3;

            n /= 10;
            // if(n==0) ans += 4;
        }
        cout << ans << '\n';
    }

    
}



