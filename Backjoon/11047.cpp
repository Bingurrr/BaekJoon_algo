#include <iostream>

using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    int money = 0;
    int idx = n-1;
    int ans = 0;
    while(money != k){
        if(money+arr[idx] <= k){
            money+= arr[idx];
            ans++;
        }
        else {
            idx--;
        }
    }
    cout << ans;
    return 0;
    
}
