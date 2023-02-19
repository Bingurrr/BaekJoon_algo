#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>
#include <bitset>
#include <set>
#include <vector>
#include <string>
#include <cstring>
#define INF 987654321

using namespace std;

int n,w,t,t1,t2;
int arr1[10001];
int arr2[10001];
int arr3[10001];

int arr_in[10001];
int arr_out[10001];


void clear(){
	memset(arr1, 0, sizeof(arr1));
	memset(arr2, 0, sizeof(arr2));
	memset(arr3,  0, sizeof(arr3));
}

void fill(){
	for(int i=2; i<=n; i++){
		int in2 =  (arr_in[i-1]+arr_in[i]<=w)  ? 1:2;
		int out2 = (arr_out[i-1]+arr_out[i]<=w)? 1:2;
		int inout2 = (arr_in[i]+arr_out[i]<=w) ? 1:2;
		
		arr1[i] = min(arr3[i-1]+1, arr2[i-1]+in2);
		arr2[i] = min(arr3[i-1]+1, arr1[i-1]+out2);
		arr3[i] = min({arr3[i-1]+inout2, arr3[i-2]+in2+out2, arr1[i]+1, arr2[i]+1});
	}
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    
	while(t--){
		int ans = INF;
		cin >> n >> w;
		for(int i=1; i<=n; i++) cin >> arr_in[i];
		for(int i=1; i<=n; i++) cin >> arr_out[i];
		
		t1 = arr_in[1];
		t2 = arr_out[1];
		
		arr1[1] = arr2[1] = 1;
		arr3[1] = (arr_in[1]+arr_out[1]<=w) ? 1:2;
		
		fill();
		ans = min(ans, arr3[n]);
		clear();
		
		if(n!=1 && arr_in[1]+arr_in[n] <= w){
			arr1[1] = arr2[1] = 1; arr3[1] = 2;
			arr_in[1] = INF;
			
			fill();
			ans = min(ans, arr2[n]);
			
			arr_in[1] = t1;
			clear();
		}
		if(n!=1 && arr_out[1]+arr_out[n] <= w){
			arr1[1] = arr2[1] = 1; arr3[1] = 2;
			arr_out[1] = INF;
			
			fill();
			ans = min(ans, arr1[n]);
			
			arr_out[1] = t2;
			clear();
		}
		if(n!=1 && arr_in[1]+arr_in[n]<=w && arr_out[1]+arr_out[n]<=w){
			arr1[1] = arr2[1] = 1; arr3[1] = 2;
			arr_in[1] = arr_out[1] = INF;
			
			fill();
			ans = min(ans, arr3[n-1]);
			
			arr_in[1] = t1;
			arr_out[1] = t2;
			clear();
		}
		cout << ans << '\n';
	}
	return 0;
}
