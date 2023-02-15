#include <iostream>

using namespace std;

long long f(long long n) {
    int x = (int)(n % 4);
    if (x == 0) {
        return n;
    } else if (x == 1) {
        return 1;
    } else if (x == 2) {
        return n+1;
    } else {
        return 0;
    }
}

int main() {
    long long a, b;
    cin >> a >> b;
    cout << (f(a-1) ^ f(b)) << endl;
    return 0;
}
