#include <iostream>

using namespace std;

int n;
int arr[11];
int ans[11];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    for(int i = 0; i < n; i++){
        int cnt = 0;
        for(int j = 0; j < n; j++){
            if(ans[j] == 0) {
                if(arr[i] ==0){
                    ans[j] = i+1;
                    break;
                }
                cnt++;
                if(cnt == arr[i]) {
                    for(int k = j+1; k < n; k++){
                        if(ans[k] == 0){
                            ans[k] = i+1;
                            break;
                        }
                    }
                    break;
                }
                }
        }
        // cout << i+1 << endl;
    }
    for(int i = 0; i <n; i++){
        cout << ans[i] << " ";
    }
    return 0;
} 