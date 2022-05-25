import java.util.*;

class Solution {

    public static int startX = Integer.MAX_VALUE;
    public static int endX = Integer.MIN_VALUE;
    public static int startY = Integer.MAX_VALUE;
    public static int endY = Integer.MIN_VALUE;

    public String[] solution(int[][] line) {
        List<List<Integer>> list = new ArrayList<>();
        long x, y;
        long a, b, e;
        long c, d, f;
        long g;
        int xi, yi;
        for(int i = 0; i < line.length - 1; i ++){
            for(int j = i+1; j < line.length; j++){
                a = line[i][0];
                b = line[i][1];
                e = line[i][2];
                c = line[j][0];
                d = line[j][1];
                f = line[j][2];
                if(a*d == b*c) continue;
                g = (a*d - b*c);
                x = (b*f - e*d);
                y = (e*c - a*f);
                if(x % g != 0 || y % g != 0) continue;
                xi  = (int) (x / g);
                yi = (int) (y / g);
                List<Integer> tmp = Arrays.asList((int) xi, (int) yi);
                if(!list.contains(tmp)) list.add(tmp);

                startX = Math.min(startX, (int) xi);
                endX = Math.max(endX, (int) xi);
                startY = Math.min(startY, (int) yi);
                endY = Math.max(endY, (int) yi);
            }
        }
                List<String> board = new ArrayList<>();
        for(int i=startY; i<=endY; i++) {
            StringBuilder sb = new StringBuilder();
            for(int j=startX; j<=endX; j++) {
                sb.append(".");
            }
            board.add(sb.toString());
        }

        for(List<Integer> intersection : list) {
            StringBuilder sb = new StringBuilder(board.get(Math.abs(intersection.get(1) - endY)));
            sb.setCharAt(Math.abs(intersection.get(0) - startX), '*');
            board.set(Math.abs(intersection.get(1) - endY), sb.toString());
        }

        String[] answer = new String[board.size()];
        for(int i=0; i<answer.length; i++) {
            answer[i] = board.get(i);
        }
        return answer;
    }
}
