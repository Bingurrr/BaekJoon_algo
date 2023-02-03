#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>
#include <bitset>
#include <set>
#include <vector>
#include <string>

using namespace std;

int n;
string a, b, c;
int ans = -1;

char change(char c){
    if(c=='1') return '0';
    return '1';
}

void solve(string &a, int cnt, int x){
    if(x== n){
        if (a[x-1] == b[x-1]){
            if(ans ==-1) ans = cnt;
            else ans = min(ans,cnt);
        }
        return;
    }
    if(a[x-1] == b[x-1]) solve(a,cnt, x+1);
    else{
        a[x-1] = change(a[x-1]);
        a[x] = change(a[x]);
        if(x+1 != n) a[x+1] = change(a[x+1]);
        solve(a,cnt+1, x+1);
    }
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    cin >> a >> b;
    c = a;
    
    solve(a,0,1);

    if(ans == -1){
        c[0] = change(c[0]);
        c[1] = change(c[1]);
        solve(c,1,1);
    }

    cout << ans;
    
    return 0;
}
