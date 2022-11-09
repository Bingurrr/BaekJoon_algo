#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int n;
int arr[10001];
long long int ans;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        }
    sort(arr,arr+n);
    for(int start = 0; start < n-2; start++){
        int mid = start + 1;
        int end = n-1;
        while(mid < end){
            long long int sum = arr[start] + arr[mid] + arr[end];
            if(sum == 0) {
                if(arr[mid] == arr[end]){
                    ans += (end-mid+1)*(end-mid)/2;
                    break;
                }
                else {
                    int tmp = arr[end];
                    int e = 0;
                    while(arr[end] == tmp){
                        e++;
                        end--;
                        }
                    tmp = arr[mid];
                    int m = 0;
                    while(arr[mid] == tmp){
                        m++;
                        mid++;
                    }
                    ans += m*e;
                }
            }
            else if (sum < 0){
                mid++;
            }
            else {
                end--;
            }
        }
    }
    cout << ans;
}