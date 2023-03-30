#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>
#include <bitset>
#include <set>
#include <vector>
#include <string>
#include <cstring>
#define INF 987654321

using namespace std;

string str;
int arr[27];
int cnt;
deque<char> ans;
char mid;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> str;

    for(int i = 0; i < str.size(); i++){
        arr[str[i]-'A']++;
    }
    for(int i = 0; i < 26; i++){
        if(arr[i]%2 == 1){
            cnt++;
            if(cnt >= 2 || (cnt >= 1 && str.size()%2==0)){
                cout << "I'm Sorry Hansoo";
                return 0;
            }
        }
    }
    
    for(int i = 0; i < 26; i++){
        if(arr[i] %2 == 1){
            mid = char('A'+i);
            ans.push_back(mid);
            arr[i]--;
            break;
        }
    }
    
    for(int i = 26; i >= 0; i--){
        while(arr[i]>0){
            arr[i]-=2;
            ans.push_back('A'+i);
            ans.push_front('A'+i);
        }
    }

    for(auto i : ans){
        cout << i;
    }
	return 0;
}
