#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>
#include <bitset>
#include <set>
#include <vector>
#include <string>
#include <cstring>
#define INF 2000000001

using namespace std;

int n;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);


    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0 ; j < i; j++){
            cout << ' ';
        }
        for(int j = 0; j < n-i; j++){
            cout << '*';
        }
        cout << '\n';
    }

    

    return 0;
}
