#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>
#include <bitset>

using namespace std;

int n, k, s;
int a[5001];
int b[10000];
int ans[5001];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    s = n;
    for(int i = 0; i < n; i++){
        a[i] = i+1;
    }
    while(cin >> b[k]) k++;

    while(true){
        for(int i = 0; i < n; i++){
            b[i] = a[i]^b[i];
        }
        ans[n-1] = b[n-1];
        int t = ans[n-1];
        for(int i = 0; i < n; i++){
            if(a[i] == t){
                a[i] = 10000;
                break;
            }
        }
        sort(a, a+n);
        n--;
        if(n==0) break;
    }
    for(int i = 0; i < s; i++){
        cout << ans[i] << " ";
    }
    
    return 0;
}

