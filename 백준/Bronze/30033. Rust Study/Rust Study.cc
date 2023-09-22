#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>
#include <bitset>
#include <set>
#include <vector>
#include <cstring>
#include <set>
#include <stack>
#include <regex>
#define INF (1 << 30)
#define endl "\n"
using namespace std;

int n, ans;
int A[1001];
int B[1001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

	cin >> n;

    for(int i = 0; i < n; i++){
        cin >> A[i];
    }
    for(int i = 0; i < n; i++){
        cin >> B[i];
    }
    for(int i = 0; i < n; i++){
        if(A[i]<= B[i]) ans++;
    }
    cout << ans;
    
}



