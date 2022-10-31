#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int n;
long long int m = 4000000000;
long long int arr[5005];
long long int ans[3];
int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for(int i = 0; i < n; i ++){
        cin >> arr[i];
    }
    sort(arr,arr+n);
    for(int start = 0; start < n-2; start++){
        int mid = start+1;
        int end = n-1;
        while(mid < end){
            long long int a = abs(arr[start]+arr[mid]+arr[end]);
            if(a < m){
                m = a;
                ans[0] = arr[start];
                ans[1] = arr[mid];
                ans[2] = arr[end];
                if(a==0) break;
            }
            if(arr[start]+arr[mid]+arr[end] < 0){
                mid++;
            }
            else end--;
        }
    }
    cout << ans[0] << " " << ans[1] << " " << ans[2];
}
