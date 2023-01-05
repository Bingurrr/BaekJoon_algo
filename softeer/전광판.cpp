#include<iostream>
#include<string>
#include<cstring>
using namespace std;

int t;
string a;
string b;

string s[10] = {"1111110", "0110000", "1101101", "1111001", "0110011", "1011011","1011111",
				"1110010", "1111111", "1111011"};

int solve(){
	int ret = 0;
	if(a.size() < 5){
		for(int i = a.size(); i < 5; i++){
			a = 'a' + a;
		}
	}
	if(b.size() < 5){
		for(int i = b.size(); i < 5; i++){
			b = 'a' + b;
		}
	}

	for(int i = 0; i < 5; i++){
		if(a[i]=='a' && b[i]=='a'){
			continue;
		}
		else if(a[i] == 'a'){
			int l = b[i] - '0';
			string y = s[l];
			string c = "0000000";
			for(int j = 0; j < 7; j++){
				if(c[j] != y[j]) ret++;
			}
			continue;
		}
		else if(b[i] =='a'){
			int l = a[i] - '0';
			string y = s[l];
			string c = "0000000";
			for(int j = 0; j < 7; j++){
				if(c[j] != y[j]) ret++;
			}
			continue;
		}
		int k = a[i] - '0';
		int l = b[i] - '0';
		string x = s[k];
		string y = s[l];
		if(k==l) continue;

		for(int j = 0; j < 7; j++){
			if(x[j] != y[j]) ret++;
		}
	}
	return ret;
}


int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> t;
	for(int i = 0; i < t; i++){
		cin >> a >> b;
		int k = solve();
		cout << k << '\n';
	}

	return 0;
}
