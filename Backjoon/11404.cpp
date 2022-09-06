#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main (void){
    int n,m;
    int a,b,c;
    cin >> n;
    cin >> m;
    int arr[n][n];
    for(int j = 0; j < n; j++){
        for(int k = 0; k < n; k++){
            if(j == k){
                arr[j][k] = 0;
            }
            else {
                arr[j][k] = 900000000;
            }
        }
    }
    for(int i = 0; i < m; i++){
        cin >> a >> b >> c;
        if (arr[a-1][b-1] > c) {
            arr[a-1][b-1] = c;
        }
    }

    for(int i = 0; i < n; i ++){
        for(int j = 0; j < n; j++){
            for(int k = 0; k < n; k++){;
                arr[j][k] = min(arr[j][k], arr[j][i] + arr[i][k]);
            }
        }
    }
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(arr[i][j] == 900000000){
                cout << 0 << " ";
            }
            else {
                cout << arr[i][j] << " ";
            }
        }
        cout << endl;
    }
    
    return 0;
}
