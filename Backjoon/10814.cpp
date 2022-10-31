#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
using namespace std;

int n;

struct id_name {
    int id;
    int idx;
    string name;
    bool operator <(const id_name &d) const{
        if(id == d.id){
            return idx < d.idx;
        }
        return id < d.id;
    } 
};



int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    id_name arr[100001];
    for(int i = 0; i < n; i++){
        cin >> arr[i].id >> arr[i].name;
        arr[i].idx = i;
    }
    sort(arr, arr+n);
    for(int i = 0; i < n; i++){
        cout << arr[i].id << " " << arr[i].name << '\n';
    }
}
