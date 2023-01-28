#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>
#include <bitset>
#include <set>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

int t;
long long int price;
long long int ans;
int a[] = {25,10};
int s[100];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    for(int i = 1; i < 100; i++){
        s[i] = i;
    }
    for(int i = 0; i < 2; i++){
        for(int j = a[i]; j < 100; j++){
            s[j] = min(s[j],s[j-a[i]]+1);
        }
    }
    // input
    cin >> t;
    for(int i = 0; i< t; i++){
        cin >> price;
        ans = 0;
        while(price > 0){
            ans += s[price%100];
            price /= 100;
        }
        cout << ans << '\n';
    }
    return 0;
}