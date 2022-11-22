#include <iostream>
#include <string>
 
using namespace std;
 
int main() {
 
    string str;
 
    while(true){
        cin>>str;
        if(str=="0"){
            break;
        }
        int cnt=0;
        int len = str.length();
 
        for(int i=0; i<len/2; i++){
            if(str[i]!=str[len-1-i]){
                continue;      
            }
            else{
                cnt++;
            }
        }
        if(cnt==len/2){
            cout<<"yes\n";
        }
        else{
            cout<<"no\n";
        }
    }
    return 0;
}
