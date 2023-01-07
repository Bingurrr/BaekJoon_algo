#include <string>
#include <vector>
#include <iostream>
#include <stack>
using namespace std;

int solution(vector<int> ingredient) {
    int answer = 0;
    int state = 0;
    stack<int> st;
    for(int i = 0; i < ingredient.size(); i = i){
        if(ingredient[i] == -1) {
            i++;
            continue;
        }
        else if(state == 0 && ingredient[i] == 1){
            state = 1;
            st.push(i);
        }
        else if(state == 0){
            state = 0;
        }
        else if(state==1 && ingredient[i] == 2){
            state = 2;
        }
        else if(state==1 && ingredient[i] == 1){
            state = 1;
            st.push(i);
        }
        else if(state==1){
            state = 0;
        }
        else if(state==2 && ingredient[i] ==3){
            state = 3;
        }
        else if(state==2 && ingredient[i] == 1){
            state = 1;
            st.push(i);
        }
        else if(state==2){
            state = 0;
        }
        else if(state == 3 && ingredient[i] == 1){
            answer++;
            state = 0;
            ingredient[i] = -1;
            int k = i;
            int state2 = 0;
            while(k>0){
                k--;
                if(ingredient[k] == 3 && state2 == 0){
                    ingredient[k] = -1;
                    state2 = 1;
                }
                else if(state2 == 1 && ingredient[k] == 2){
                    ingredient[k] = -1;
                    state2 = 2;
                }
                else if(state2 == 2 && ingredient[k] == 1){
                    ingredient[k] = -1;
                    break;
                }
            }
            while(!st.empty()){
                int a = st.top();
                st.pop();
                if(ingredient[a] == 1){
                    i = a-1;
                    break;
                }
            }
        }
        else if(state==3){
            state = 0;
        }
        i++;
    }
    return answer;
}