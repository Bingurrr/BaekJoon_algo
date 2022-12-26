#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

int n, k;
int idx, s;
int arr[100001];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> k;
        if(k ==0){
            idx--;
        }
        else{
            arr[idx] = k;
            idx++;
        }
    }
    for(int i = 0; i < idx; i++){
        s += arr[i];
    }
    cout << s;
    return 0;
}