#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>
#include <bitset>
#include <set>
#include <vector>
#include <cstring>
#include <set>
#define INF 2000000001

using namespace std;


int n, m;
long long int p[1001];
long long int sum_price;
int price;

bool cmp(int x, int y){
    return x > y;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for(int i = 0; i < m; i++){
        cin >> p[i];
    }
    sort(p, p+m, cmp);
    price = p[0];
    for(int i = 0; i < m; i++){
        if( i < n){
            if( p[i]*(i+1) > sum_price){
                sum_price = p[i]*(i+1);
                price = p[i];
            }
        }else break;
    }
    cout << price << " " << sum_price;

    
	return 0;
}