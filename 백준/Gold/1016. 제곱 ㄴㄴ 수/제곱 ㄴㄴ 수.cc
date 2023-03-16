#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>
#include <bitset>
#include <set>
#include <vector>
#include <string>
#include <cstring>
#include <stack>
#define INF 987654321

using namespace std;

long long int num[1000001];
long long int a, b, ans;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> a >> b;
    for(long long int i = 2; i * i <= b; i++){
        long long int n = a/(i*i);

        if(a%(i*i)){
            n++;
        }

        while(n*i*i <= b){
            num[n*i*i-a] = 1;
            n++;
        }
    }

    for(int i = 0; i <= b-a; i++){
        if(num[i]==0) ans++;
    }
    cout << ans;
    
    return 0;
}
