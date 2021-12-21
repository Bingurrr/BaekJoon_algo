class Solution {
    public String solution(int[] numbers, String hand) {
        String answer = "";
        int left = 10;
        int right = 12;
        int left_distance = 0;
        int right_distance = 0;
        //자판 0일경우 11을 대입
        for(int j = 0; j<numbers.length; j++){
            if(numbers[j]==0){
                numbers[j] = 11;
            }
        }
        for(int i = 0; i<numbers.length; i++){
            //147인경우
            if(numbers[i]%3==1){
                answer+="L";
                left = numbers[i];
            }
            //369인경우
            else if(numbers[i]%3==0){
                answer+="R";
                right = numbers[i];
            }
            //2580인 경우
            else {
                left_distance = 0;
                right_distance = 0;
                //왼손거리
                switch(left-numbers[i]){
                    case 3 : case -3 : case 1: case -1 : left_distance = 1;
                        break;
                    case 2 : case -4 : case 6: case -6 : left_distance = 2;
                        break;
                    case 5 : case -7 : case 9 : case -9 : left_distance = 3;
                        break;
                    case 8: case -10 : left_distance = 4;
                        break;
                }
                //오른손거리
                switch(right-numbers[i]){
                    case 3 : case -3 : case 1: case -1 : right_distance = 1;
                        break;
                    case 4 : case -2 : case 6: case -6 : right_distance = 2;
                        break;
                    case 7 : case -5 : case 9 : case -9 : right_distance = 3;
                        break;
                    case -8: case 10 : right_distance = 4;
                        break;
                }
                //거리계산
                if(left_distance<right_distance){
                    answer+="L";
                    left = numbers[i];
                }
                else if(left_distance>right_distance){
                    answer+="R";
                    right = numbers[i];
                }
                else {
                    if(hand.equals("left")){
                        answer+="L";
                        left = numbers[i];
                    }
                    else{
                        answer+="R";
                        right = numbers[i];
                    }
                }
           
            }
        }
        return answer;
    }
}
