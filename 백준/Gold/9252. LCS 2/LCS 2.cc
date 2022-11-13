#include <iostream>
#include <string>
#include <cstring>
#define MAX 1001

using namespace std;
char str1[MAX];
char str2[MAX];
int arr[MAX][MAX];
int num[MAX][MAX];
int ans;

int str_len(char* s){
    int l = 0;
    for(int i = 0; i < 101; i++){
        if(s[i] == '\0') break;
        else l++;
    }
    return l;
}

int LCS(char s[], char t[], int m, int n){
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            if(s[i-1]==t[j-1]){
                arr[i][j] = arr[i-1][j-1] +1;
            }
            else {
                arr[i][j] = max(arr[i][j-1], arr[i-1][j]);
                if(arr[i][j] == arr[i][j-1]) num[i][j] = 1;
                else num[i][j] = 2;
            }
        }
    }
    return arr[m][n];
}

void printLCS(char s[], char t[], int m, int n){
    if(m <= 0 || n <= 0) return;
    if(num[m][n] == 0){
        printLCS(s,t,m-1,n-1);
        cout << s[m-1];
    }
    else if (num[m][n] == 1){
        printLCS(s,t,m,n-1);
    }
    else if(num[m][n] == 2){
        printLCS(s,t,m-1,n);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> str1 >> str2;
    ans = LCS(str1, str2, (int)strlen(str1), (int)strlen(str2));
    cout << ans << '\n';
    if(ans!= 0) printLCS(str1,str2,(int)strlen(str1), (int)strlen(str2));
        
}