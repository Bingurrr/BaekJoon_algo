#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define MAX 3020

using namespace std;

long long int n, m, q;
long long int a, b, c, d;
long long int r;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> q;
    int ** arr = new int*[n];
    for(int i = 0; i < n; i++){
        arr[i] = new int[m];
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> arr[i][j];
        }
    }
    for(int t = 0; t < q; t++){
        cin >> a >> b >> c;
        if(a == 1){
            if(b==c) continue;
            swap(arr[b], arr[c]);
        }
        else {
            cin >> d;
            arr[b][c] = d;
        }
    }
    for(int i = 0; i < n; i++){
        // cout << row[i] << endl;
        for(int j = 0; j < m; j++){
            cout << arr[i][j] << " ";
        }
        cout << '\n';
    }
    
}