#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>
#include <bitset>
#include <set>
#include <vector>

using namespace std;

int n, s;
int arr[100001];
double ans;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        s+= arr[i];
    }
    sort(arr, arr+n);
    ans = arr[n-2];
    if(double(s)/double(n) > ans) ans = double(s)/double(n);
    
    cout.precision(30);
    cout << ans;
	return 0; 
}