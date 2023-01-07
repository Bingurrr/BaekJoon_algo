#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int i;

bool cmp(string a, string b){
    if(a[i] != b[i]) return a[i] < b[i];
    else {
        return a < b;
    }
}

vector<string> solution(vector<string> strings, int n) {
    vector<string> answer;
    i = n;
    sort(strings.begin(), strings.end(), cmp);
    
    return strings;
}