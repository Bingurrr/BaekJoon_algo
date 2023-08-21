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

char s;
string ans[5] = {"MatKor", "WiCys", "CyKor", "AlKor", "$clear"};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> s;
    if (s == 'M'){
        cout << ans[0];
    }
    else if(s=='W') cout << ans[1];
    else if(s=='C') cout << ans[2];
    else if(s=='A') cout << ans[3];
    else cout << ans[4];

    return 0;
}


