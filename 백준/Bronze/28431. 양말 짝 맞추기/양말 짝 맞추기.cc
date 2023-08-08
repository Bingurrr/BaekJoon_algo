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

using namespace std;

int n;
int arr[10];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    while(cin >> n){
        arr[n]++;
    }
    for(int i = 0; i < 10; i++){
        if(arr[i] %2 == 1){
            cout << i;
            return 0;
        }
    }

    return 0;
}


