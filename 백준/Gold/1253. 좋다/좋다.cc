#include <iostream>
#include <algorithm>
#define MAX 2001
using namespace std;

int n;
int arr[MAX];
long long int ans, sum;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    sort(arr,arr+n);
    for(int i = 0; i < n; i++){
        int s = 0;
        int e = n-1;
        while(s < e){
            if(s==i) s++;
            if(e==i) e--;
            if(s >= e) break;
            sum = arr[s] + arr[e];
            if(sum == arr[i]) {
                ans++;
                break;
            }
            else if(sum < arr[i]){
                s++;
            }
            else {
                e--;
            }
        }
    }
    cout << ans;
}