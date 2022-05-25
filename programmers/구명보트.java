import java.util.Arrays;

class Solution {
    public int solution(int[] people, int limit) {
        int cnt = 0;    
        int s = 0;
        int e = people.length-1;
        Arrays.sort(people);
        System.out.println(people[0]);
        //if(e%2 == 0) cnt++;
        while(e > s ){
            if(people[s] + people[e] <= limit){
                cnt++;
                e--;
                s++;

            }
            else {
                cnt++;
                e--;  
            }
        }
        if(e==s) cnt++;
        return cnt;
    }
}
