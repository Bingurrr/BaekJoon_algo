#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<pair<int, int>> v;
int n;
int a, b;

bool cmp(int a[], int b[]){
    if(a[0] > b[0]){
        return true;
    }
    else if(a[0] < b[0]){
        return false;
    }
    else{
        if(a[1] > b[1]) return true;
        else return false;
    }
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a >> b;
        v.push_back(make_pair(a,b));
    }
    sort(v.begin(), v.end());
    for(int i = 0; i < n; i++){
        cout << v[i].first << " " << v[i].second << '\n';
    }
}