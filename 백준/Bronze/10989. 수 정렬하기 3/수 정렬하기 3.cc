#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

int n, k;
int arr[10001];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> k;
        arr[k]++;
    }
    for(int i = 1; i < 10001; i=i){
        if(arr[i] > 0){
            cout << i << '\n';
            arr[i]--;
        }
        else {
            i++;
        }
    }
    return 0;
}