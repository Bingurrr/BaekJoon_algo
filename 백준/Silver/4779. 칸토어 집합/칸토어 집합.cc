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

void sol(int x){
    if(x==0) {
        cout << '-';
        return;
    }
    sol(x-1);
    int t = int(pow(3,x-1));

    for(int i = 0; i < t; i++){
        cout << ' ';
    }

    sol(x-1);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    while(cin >> n){
        sol(n);
        cout << '\n';
    }

    return 0;
}
