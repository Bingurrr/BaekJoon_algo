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

int ans, m;
int n, x, a,b,c;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> x;

    cin >> a >> b;
    m = a + b;
    ans = m;
    
    for(int i = 2; i < n; i++){
        cin >> c;
        if(ans > m - a + c){
            ans = m - a + c;
        }
        m -= a;
        m += c;
        a = b;
        b = c;
    }
    cout << ans * x;

    return 0;
}


