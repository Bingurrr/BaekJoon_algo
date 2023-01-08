#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>
#include <bitset>
#include <set>
#include <vector>
#include <cstring>
#include <set>
#define INF 1000002

using namespace std;

int n;
set<int> s;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    while(cin >> n){
        s.insert(n%42);
    }
    cout << s.size();
	return 0; 
}
