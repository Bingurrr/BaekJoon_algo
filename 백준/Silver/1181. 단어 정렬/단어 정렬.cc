#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#define MAX 51

using namespace std;

int n;
vector<string> v;


bool cmp(string b, string a){
    if(a.length() > b.length()) return true;
    else if(b.length() > a.length()) return false;
    else {
        for(int i = 0; i < a.length(); i++){
            if(a[i] > b[i]) return true;
            else if (a[i] < b[i]) return false;
        }
    }
    return true;
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    string str;
    for(int i = 0; i < n; i++){
        cin >> str;
        auto it = find(v.begin(), v.end(), str);
        if(it == v.end()) v.push_back(str);
    }
    sort(v.begin(), v.end(), cmp);
    for(auto s : v){
        cout << s << '\n';
    }
}