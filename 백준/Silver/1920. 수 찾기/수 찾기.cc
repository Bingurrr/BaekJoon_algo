#include <iostream>
#include <cmath>
#include <algorithm>
#define MAX 100010

using namespace std;

int n1,n2;
int a[MAX];
int m[MAX];

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n1;
    for(int i = 0; i < n1; i++){
        cin >> a[i];
    }
    cin >> n2;
    for(int i = 0; i < n2; i++){
        cin >> m[i];
    }
    sort(a,a+n1);
    for(int i = 0; i < n2; i++){
        if(binary_search(a, a+n1, m[i])){
            cout << 1 << '\n';
        }
        else {
            cout << 0 << '\n';
        }
    }
}