#include <iostream>
using namespace std;

int t, n;
int arr[20];
int ans;
bool check = false;

int ispromising(int row)
{
    int a = 0;
    int p = 1;
    while (a < row && p)
    {
        if (arr[row] == arr[a] || abs(arr[row] - arr[a]) == row - a)
        {
            p = 0;
        }
        a++;
    }
    return p;
}

void solve(int row)
{
    if (row == n){
        ans++;
        return;
    }
    for (int i = 0; i < n; i++){ 
        arr[row] = i;
        if (ispromising(row))
        {
            solve(row + 1);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    solve(0);
    cout << ans;
    return 0;
}