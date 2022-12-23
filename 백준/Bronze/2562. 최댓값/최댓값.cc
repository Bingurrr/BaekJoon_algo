#include<iostream>

using namespace std;

int n;
int ans, idx, big;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    idx++;
    while(cin >> n){
        if(n > big){
            big = n;
            ans = idx;
        } 
        idx++;
    }
    cout << big << '\n' << ans;
    return 0;
}