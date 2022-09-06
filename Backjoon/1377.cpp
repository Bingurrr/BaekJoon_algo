#include <iostream>
//https://www.acmicpc.net/problem/1377

#include <algorithm>
#include <vector>

using namespace std;

int main (void){
    int n, tmp;
    int max = 0;
    cin >> n;
    vector <pair<int, int>> vec;

    // bool cmp(x,y) {
    //     if (x[1] > y[1]){
    //         return true;
    //     }
    //     else {
    //         return false;
    //     }
    // }
    for(int i = 0; i < n; i++){
        cin >> tmp;
        vec.push_back(pair<int, int>(tmp,i));
    }
    sort(vec.begin(), vec.end());
    for(int j = 0; j < n; j++){
        // cout << vec[j].second << endl;
        if (vec[j].second - j > max) {
            max = vec[j].second - j;
        }
    }
    
    cout << max + 1;

    return 0;
}
