#include<iostream>

using namespace std;

int n;
int ans;
int arr[11];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ans = 1;
    while(cin >> n){
        ans *= n;   
    }
    while(ans > 0){
        int k = ans%10;
        arr[k]++;
        ans /= 10;
    }
    for(int i = 0; i < 10; i++){
        cout << arr[i] << '\n';
    }
    return 0;
}