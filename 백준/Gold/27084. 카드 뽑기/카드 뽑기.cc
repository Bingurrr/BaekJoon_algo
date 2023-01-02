#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>
#include <bitset>
#include <set>
#include <vector>

using namespace std;

int n, x;
int arr[200002];
long long int a;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);	
	cin >> n;
    for(int i = 0; i < n; i++){
        cin >> x;
        arr[x]++;
    }
    a = 1;
    for(int i = 1; i <= n; i++){
        a *= (arr[i]+1);
        a %= 1000000007;
    }
    cout << a-1 << endl;
	return 0; 
}