#include<iostream>

using namespace std;

int n;
double big, s, ans;
int arr[1001];


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        if(arr[i] > big){
            big = arr[i];
        }
    }
    for(int i = 0; i < n; i++){
        s += arr[i]/big *100;
    }
    ans = s/n;
    cout.precision(30);
    cout << ans;
    return 0;
}