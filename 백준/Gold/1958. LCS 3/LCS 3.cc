#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>
#include <bitset>
#include <set>
#include <vector>
#include <string>
using namespace std;


int dp[102][102][102];
char s1[102];
char s2[102];
char s3[102];

int max(int a, int b, int c) {
    return max(max(a, b), c);
}

int strlen(char s[]){
    int ret = 0;
    for(int i = 0; i < 101; i++){
        if(s[i]=='\0') break;
        ret++;
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> s1;
    cin >> s2;
    cin >> s3;
    for(int i = 0; i <= strlen(s1); i++) {
        for(int j = 0; j <= strlen(s2); j++) {
            for(int k = 0; k <= strlen(s3); k++) {
                if(s1[i] == s2[j] && s2[j] == s3[k]) {
                    dp[i+1][j+1][k+1] = dp[i][j][k] + 1;
                }
                else { 
                    dp[i+1][j+1][k+1] = max(dp[i][j+1][k+1], dp[i+1][j][k+1], dp[i+1][j+1][k]);
                }
            }
        }
    }
    cout << dp[strlen(s1)][strlen(s2)][strlen(s3)];
}

