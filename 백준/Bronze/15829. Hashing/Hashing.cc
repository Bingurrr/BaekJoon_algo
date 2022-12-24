#include <iostream>
#include <cmath>
#include <algorithm>
#define M 1234567891

using namespace std;

int n;
char s[51];
long long int ans;
long long int r;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    cin >> s;
    r = 1;
    for(int i = 0; i < n; i++){
        int k = s[i]-'a'+1;
        ans = (ans + k*r)%M;
        r = (r*31)%M;
    }
    cout << ans;

    
    return 0;
}