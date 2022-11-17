#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define MAX 3100

using namespace std;

long long int n;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    if(n%2==0) cout << "CY";
    else cout << "SK";
    
}