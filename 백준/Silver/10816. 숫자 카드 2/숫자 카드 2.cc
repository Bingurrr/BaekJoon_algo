#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstring>
#include <stack>
#include <unordered_map>

using namespace std;
unordered_map <int, int> mm;
int n, m, x;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> x;
        mm[x]++;
    }
    cin >> m;
    for(int i = 0; i < m; i++){
        cin >> x;
        cout << mm[x] << " ";
    }
    
    return 0;
}