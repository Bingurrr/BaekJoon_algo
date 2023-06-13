#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int l, c;
char arr[16];
bool visited[16];

bool is_secret(string k) {
    int a = 0;
    int b = 0;

    for (int i = 0; i < k.size(); i++) {
        if (k[i] == 'a' || k[i] == 'e' || k[i] == 'i' || k[i] == 'o' || k[i] == 'u') {
            a++;
        }
        else {
            b++;
        }
    }
    if (a > 0 && b > 1) {
        return true;
    }
    return false;
}

void dfs(string str, int n) {
    if (n == c+1) return;
    if (str.size() == l) {
        if (is_secret(str)) {
            cout << str << '\n';
        }
        return;
    }
    string new_str = str;

    new_str += arr[n];
    dfs(new_str, n + 1);
    dfs(str, n+1);
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> l >> c;

    for (int i = 0; i < c; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + c);

    dfs("", 0);


    return 0;
}