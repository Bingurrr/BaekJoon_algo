#include <iostream>

using namespace std;
long long int x, y, k;
int main(void) {
    cin >> x >> y;
    long long int t = 99 * x - 100 * y;
    long long int ans;
    if(100*y/x >= 99) cout << -1;
    else{
        ans = x*x /t;
        if(100*y/x+1 <= ((100*y/x+ans)/(x+ans))) cout << ans+1;
        else cout << ans;
    }
    return 0;
}
