#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#define MAX 1111
using namespace std;

int arr[MAX][MAX];
string a;
string b;
string ans;
int l1;
int l2;


int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> a;
    cin >> b;
    l1 = a.length();
    l2 = b.length();
    
    
    // LCS
    for(int i = 1; i <= l1; i++){
        for(int j = 1; j <= l2; j++){
            if(a[i-1] == b[j-1]){
                arr[i][j] = arr[i-1][j-1]+1;
            }
            else {
                arr[i][j] = max(arr[i][j-1], arr[i-1][j]);
            }
        }
    }
    
    cout << arr[l1][l2];
    

	return 0;
}