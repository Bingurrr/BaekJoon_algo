#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>
#include <bitset>
#include <set>
#include <vector>
#include <cstring>
#include <set>
#include <stack>
#define INF 2000000001

using namespace std;

string str;
string ans = "zzzzzz";

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
	cin >> str;
    
	for (int i = 0; i < str.size() - 2; i++){
		for (int j = i + 1; j < str.size() - 1; j++){
			string s;
			for (int k = i; k >= 0; k--){
				s += str[k];
            }
			for (int k = j; k > i; k--){
                s += str[k];
            }
			for (int k = str.size()-1; k > j; k--){
                s += str[k];
            }
			if (ans > s) ans = s;
		}
	}

	cout << ans;
   
	return 0;
}
