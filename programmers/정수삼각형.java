import java.util.*;

class Solution {
    public int solution(int[][] triangle) {
        int answer = 0;
        int height = triangle.length;
        int max = 0;
        for(int i = 1; i < height; i ++){
            for(int j = 0; j < i+1; j ++){
                if (j==0) triangle[i][j] += triangle[i-1][j];
                else if(i == j) triangle[i][j] += triangle[i-1][j-1];
                else {
                    max = triangle[i-1][j] > triangle[i-1][j-1] ? triangle[i-1][j] : triangle[i-1][j-1];
                    triangle[i][j] += max;
                }
            }
        }
        Arrays.sort(triangle[height-1]);
        answer = triangle[height-1][height-1];
        return answer;
    }
}
