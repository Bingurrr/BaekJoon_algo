class Solution {
    public int[] solution(int rows, int columns, int[][] queries) {
        int r1, r2, c1, c2, min;
        int[] result = new int[queries.length];
        int[][] answer = new int[rows][columns];
        int[][] bef = new int[rows][columns];
        for (int i = 0; i < rows; i++){
            for (int j = 0; j < columns; j++){
                answer[i][j] = i*columns + j + 1;
                bef[i][j] = i*columns + j + 1;
            }
        }
        for(int i = 0; i < queries.length; i++){
            //bef = answer;
            r1 = queries[i][0];
            r2 = queries[i][2];
            c1 = queries[i][1];
            c2 = queries[i][3];
            min = answer[r1-1][c1-1];
            for(int j = r1-1; j < r2; j ++){
                for(int k = c1-1; k < c2; k++){
                    if(r1==j+1 && c1 ==k+1){
                        answer[j][k] = bef[j+1][k];
                        if(min > bef[j+1][k]){
                            min = bef[j+1][k];
                        }
                    }

                    else if(r2==j+1 && c2 ==k+1){
                        answer[j][k] = bef[j-1][k];
                        if(min > bef[j-1][k]){
                            min = bef[j-1][k];
                        }
                    }
                    else if(r1==j+1 ){
                        answer[j][k] = bef[j][k-1];
                        if(min > bef[j][k-1]){
                            min = bef[j][k-1];
                        }
                    }
                    else if(r2==j+1 ){
                        answer[j][k] = bef[j][k+1];
                        if(min > bef[j][k+1]){
                            min = bef[j][k+1];
                        }
                    }
                    else if(c1==k+1 ){
                        answer[j][k] = bef[j+1][k];
                        if(min > bef[j+1][k]){
                            min = bef[j+1][k];
                        }
                    }
                    else if(c2==k+1){
                        answer[j][k] = bef[j-1][k];
                        if(min >  bef[j-1][k]){
                            min = bef[j-1][k];
                        }
                    }
                    else{
                        continue;
                    }
                }
            }
            result[i] = min;
            for (int a = 0; a < rows; a++){
            for (int b = 0; b < columns; b++){
                bef[a][b] = answer[a][b];
            }
        }
        }
        return result;
    }
}
