#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>
#include <bitset>
#include <set>
#include <vector>
#include <string>

using namespace std;

string str;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> str;
    int one = 0;
	
	for(int i = 0; i < str.length(); i++){
		if(str[i] == 'P'){
			one++;
			continue;
		}
		
		if(one >=2 && str[i+1] == 'P'){
			one--;
			i++;
		}
		
		else{
			cout << "NP\n";
			return 0;
		}
	}
	
	if(one == 1) cout << "PPAP";
	else cout << "NP";
	return 0;
}
