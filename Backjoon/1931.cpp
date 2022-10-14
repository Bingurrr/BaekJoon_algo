#include <iostream>
#include <string>
#include <algorithm>
//divide and conquer
using namespace std;

int n;
int cnt;

struct time_table{
    int start;
    int end;
    bool operator<(const time_table &t) const {
        if(end == t.end) return start < t.start;
        return end < t.end; 
    }
};


int main(){
    cin >> n;
    time_table arr[n];
    for(int i = 0 ; i < n; i++){
        cin >> arr[i].start >> arr[i].end;
    }
    long long int end_min;
    long long int start_max = 0;

    sort(arr, arr+n);
    int j = 0;
    for(int i = j; i < n; i++){
        if(arr[i].start >= start_max){
            end_min = arr[i].end;
            j = i;
            cnt++;
            start_max = end_min;
            if(end_min ==2147483647) break;
        }
    }
    
    cout << cnt;
    
    return 0;
}
