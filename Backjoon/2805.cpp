#include <iostream>

using namespace std;

int n,m;
long long int sum;

int main(){

    cin >> n >> m;
    int arr[n];
    int max = 0;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        if(arr[i] > max) max = arr[i];
    }
    int start = 0;
    int end = max;
    int ans = 0;
    while(start <= end){
        sum = 0;
        int mid = (start + end) / 2;
        for(int i = 0; i < n; i++){
            if(arr[i] > mid) sum += arr[i] - mid;
            if(sum > m) break;
        }
        if(sum >= m) {
            start = mid +1;
            ans = mid;
        }
        else {
            end = mid -1;
        }
    }
    cout << ans;
    return 0;
}
