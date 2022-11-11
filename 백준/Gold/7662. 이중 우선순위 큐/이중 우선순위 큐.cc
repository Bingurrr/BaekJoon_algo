#include <iostream>
#include <algorithm>
#include <set>

#define MAX 32001
using namespace std;

int n,a, b;
char s;
int value;
long long int cnt;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++){
        multiset<int> multi;
        cin >> b;
        for(int j = 0; j < b; j++){
            cin >> s >> value;
            if(s=='I'){
                cnt++;
                multi.insert(value);
            }
            else {
                cnt--;
                if(value== -1 && !multi.empty()){
                    multi.erase(multi.begin());
                }
                if(value== 1 && !multi.empty()){
                    multi.erase(--multi.end());
                }
            }
        }
        if(multi.empty()){
            cout << "EMPTY" << '\n';
        }
        else {
            cout << *(--multi.end()) << " " << *multi.begin() << '\n';
        }
        cnt = 0;
    }
}