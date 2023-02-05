#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>
#include <bitset>
#include <set>
#include <vector>
#include <string>
#include <cstring>
#include <map>
using namespace std;


int N, S;
int arr[41];
map<int, int> total;
long long int ans;


void left(int s, int sum) {
	if (s == N / 2) {
		total[sum]++;
		return;
	}
	left(s + 1, sum);
	left(s + 1, sum + arr[s]);
}

void right(int s, int sum) {
	if (s == N) {
		ans += total[S-sum];
		return;
	}
	right(s + 1, sum);
	right(s + 1, sum + arr[s]);
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> S;
    for(int i = 0; i < N; i++){
        cin >> arr[i];
    }
    left(0,0);
    right(N/2, 0);

    if(S==0) cout<< ans-1;
    else cout << ans;

    return 0;
}
