#include <iostream>
#include <algorithm>
#define MAX_SIZE 100001

using namespace std;

int n;
int tree[MAX_SIZE];
int term[MAX_SIZE];
int ans;

int gcd(int a, int b){
    if(a==0) return b;
    return gcd(b%a, a);
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++) cin >> tree[i];
    sort(tree, tree+n);
    for(int i = 0; i < n-1; i++){
        term[i] = abs(tree[i+1] - tree[i]);
    }
    int g = term[0];
    for(int i = 1; i < n-1; i++){
        if (g < term[i]) g = gcd(g,term[i]);
        else g = gcd(term[i], g);
    }
    //cout << g;
    for(int i = 0; i < n-1; i++){
        ans += (term[i] / g) - 1;
    }
    cout << ans;
}
