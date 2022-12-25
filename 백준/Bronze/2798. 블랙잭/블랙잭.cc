#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

int n, k;
int arr[100];
int t, m;
int ans;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    m = k;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    for(int i = 0; i < n-2; i++){
        for(int j = i+1; j < n-1; j++){
            for(int s = j+1; s < n; s++){
                if(arr[i]+arr[j]+arr[s] > ans && arr[i]+arr[j]+arr[s]-k <= 0){
                    ans = arr[i]+arr[j]+arr[s];
                }
            }
        }
    }
    cout << ans;
    
    return 0;
}