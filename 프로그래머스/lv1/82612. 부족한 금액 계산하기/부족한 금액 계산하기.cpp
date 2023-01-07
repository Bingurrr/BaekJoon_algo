using namespace std;

long long solution(int price, int money, int count)
{
    long long answer = 0;
    long long int p = price;
    long long int c = count;
    long long int m = money;
    long long int k = p*c*(c+1)/2;
    if(m - k < 0){
        answer = k - m;
    }
    return answer;
}