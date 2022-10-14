#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

int n;

int main(){
    cin >> n;
    int k = pow(2,n)-1;
    int arr[k];
    for(int i = 0; i < k; i++){
        cin >> arr[i];
    }
    int p = n-1;
    int start = pow(2,p)-1;
    int gap = pow(2,p);
    while(true){
        for(int i = start; i < k; i+=gap){
            cout << arr[i] << " ";
        }
        p--;
        start = pow(2,p)-1;
        gap = pow(2,p+1);
        cout << endl;
        if(p==-1) break;
    }
    return 0;
}
