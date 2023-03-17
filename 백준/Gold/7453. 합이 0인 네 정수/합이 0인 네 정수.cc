#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>
#include <bitset>
#include <set>
#include <vector>
#include <string>
#include <cstring>
#include <stack>
#define INF 987654321
using namespace std;

int n;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    int A[n], B[n], C[n], D[n];
    for (int i = 0; i < n; i++) {
        cin >> A[i] >> B[i] >> C[i] >> D[i];
    }

    long long int AB[n * n], CD[n * n];
    long long int ab_index = 0, cd_index = 0;

    // A와 B를 더한 값들을 오름차순으로 정렬하여 AB에 저장
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            AB[ab_index++] = A[i] + B[j];
        }
    }
    sort(AB, AB + ab_index);

    // C와 D를 더한 값들을 오름차순으로 정렬하여 CD에 저장
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            CD[cd_index++] = C[i] + D[j];
        }
    }
    sort(CD, CD + cd_index);

    long long int ab_ptr = 0, cd_ptr = cd_index - 1;
    long long int count = 0;

    // AB와 CD를 각각 순회하면서 합이 0인 쌍의 개수를 찾기
    while (ab_ptr < ab_index && cd_ptr >= 0) {
        long long int sum = AB[ab_ptr] + CD[cd_ptr];
        if (sum == 0) {
            long long int ab_cnt = 0, cd_cnt = 0;
            // AB에서 중복된 값을 찾아 개수를 세기
            while (ab_ptr < ab_index - 1 && AB[ab_ptr] == AB[ab_ptr + 1]) {
                ab_ptr++;
                ab_cnt++;
            }
            ab_ptr++;

            // CD에서 중복된 값을 찾아 개수를 세기
            while (cd_ptr > 0 && CD[cd_ptr] == CD[cd_ptr - 1]) {
                cd_ptr--;
                cd_cnt++;
            }
            cd_ptr--;

            count += (ab_cnt + 1) * (cd_cnt + 1);
        }
        else if (sum < 0) {
            ab_ptr++;
        }
        else {
            cd_ptr--;
        }
    }

    cout << count << endl;

    return 0;
}
