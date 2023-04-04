#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>
#include <bitset>
#include <set>
#include <vector>
#include <cstring>
#include <set>
#define INF 2000000001

using namespace std;


int ans;
string s1, s2;
double n;
double grade;
double sub;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    while(cin >> s1 >> n >> s2){
        if(s2 == "A+"){
            sub += n;
            grade += n*4.5;
        }
        else if(s2 == "A0"){
            sub += n;
            grade += n*4.0;
        }
        else if(s2 == "B+"){
            sub += n;
            grade += n*3.5;
        }
        else if(s2 == "B0"){
            sub += n;
            grade += n*3.0;
        }
        else if(s2 == "C+"){
            sub += n;
            grade += n*2.5;
        }
        else if(s2 == "C0"){
            sub += n;
            grade += n*2.0;
        }
        else if(s2 == "D+"){
            sub += n;
            grade += 1.5*n;
        }
        else if(s2 == "D0"){
            grade += 1.0*n;
            sub+=n;
        }
        else if(s2=="F"){
            sub += n;
        }
        else{
            continue;
        }
    }

    cout.precision(30);
    cout << grade/sub;
    
	return 0;
}