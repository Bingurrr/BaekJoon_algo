#include <string>
#include <vector>

using namespace std;

int solution(int m, int n) {
    int answer = m-1 + (n-1) * m;
    return answer;
}