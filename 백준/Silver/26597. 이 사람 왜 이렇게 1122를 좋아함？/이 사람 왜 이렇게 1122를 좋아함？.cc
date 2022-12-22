#include<iostream>

using namespace std;

int n, ch;
char s;
long long int a, ans;
long long int start, finish;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    start = -1000000000000000001;
    finish = 1000000000000000001;
    for(int i = 0; i < n; i++){
        cin >> a >> s;
        if(s=='^'){
            if(a > start){
                start = a;
            }
        }
        else {
            if(a < finish){
                finish = a;
            }
        }
        if(start+1 >= finish){
            cout << "Paradox!" << '\n';
            cout << i+1;
            return 0;
        }
        if(finish-start == 2 && ch == 0){
            ans = i+1;
            ch = 1;
        }
    }
    if(ch == 0) cout << "Hmm...";
    else {
        cout << "I got it!" << '\n';
        cout << ans;
    }
    return 0;
}