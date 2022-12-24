#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

struct dragon{
    int p, idx;
};

int n, m, k;
dragon arr[1000002];

bool cmp(dragon i, dragon j){
    return i.p > j.p;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    k = n;
    for(int i = 1; i <= n; i++){
        cin >> arr[i].p;
        arr[i].idx = i;
        
    }
    sort(arr+1, arr+n+1, cmp);
    for(int i = 1; i <= n-1; i++){
        if(arr[i].p > arr[i+1].p + m){
            k = i;
            break;
        }
    }
    // cout << l << endl;
    if(k == n){
        cout << "YES" << '\n';
        for(int i = 1; i <= n; i++){
            cout << arr[i].idx << " ";
        }
    }
    else if(n < 4){
        cout << "NO";
    }
    else {
        // cout << l << endl;
        if(k <= 3){
            cout << "NO";
        }
        else {
            cout << "YES" << '\n';
            cout << arr[1].idx << " " << arr[2].idx << " ";
            for(int i = k+1; i <= n; i++){
                cout << arr[i].idx << " ";
            }
            for(int i = 3; i <= k; i++){
                cout << arr[i].idx << " ";
            }
        }
    }
    
    return 0;
}