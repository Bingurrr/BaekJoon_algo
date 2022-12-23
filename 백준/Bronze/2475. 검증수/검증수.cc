#include<iostream>

using namespace std;

int n;
int ans;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    while(cin >> n){
        ans += n*n; 
    }
    cout << ans%10;
    return 0;
}