#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>
#include <bitset>
#include <set>
#include <vector>
#include <cstring>
#include <set>
#define INF 2000000001

using namespace std;

int n;
int arr[500001];
int ans1, ans2;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ans1 = INF;
    ans2 = INF;
    
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    sort(arr, arr+n);
    for(int i = 0; i < n-1; i++){
        int a = INF;
        if(i+2 < n){
            a = arr[i+2] - arr[i];
        }
        int k = (arr[i+1]-arr[i]);
        if(k%2 == 0 && k < ans1){
            ans1 = k;
        }
        else if(a % 2 == 0 && a < ans1){
            ans1 = a;
        }
        if(k%2==1 && k < ans2){
            ans2 = k;
        }
    }
    if(ans1 == INF){
        ans1 = -1;
    }
    if(ans2 == INF){
        ans2 = -1;
    }
    cout << ans1 << " " << ans2;


    
	return 0;
}