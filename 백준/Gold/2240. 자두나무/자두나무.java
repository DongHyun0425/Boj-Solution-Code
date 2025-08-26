import java.io.*;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());
        int T = Integer.parseInt(st.nextToken());
        int W = Integer.parseInt(st.nextToken());

        int[] jaduArr = new int[T + 1];
        for (int i = 1; i <= T; i++) {
            jaduArr[i] = Integer.parseInt(br.readLine());
        }
        int result = Integer.MIN_VALUE;

        int[][] dp = new int[W + 1][T + 1];
        for (int i = 1; i <= T; i++) {
            if (jaduArr[i] == 1) {
                dp[0][i] = dp[0][i - 1] + 1;
                result = Math.max(result, dp[0][i]);
            }
        }

        // 처음에 1번에 있으므로 홀수번 움직였다면 2번에 있고 짝수번 움직였다면 1번에 있을 것이다.
        for (int i = 1; i <= W; i++) {
            for (int j = 1; j <= T; j++) {
                // 짝수번 움직였다면 1번 사과를 먹을 것이다.
                if ((i % 2 == 0 && jaduArr[j] == 1) || (i % 2 == 1 && jaduArr[j] == 2)) {
                    dp[i][j] = dp[i][j - 1] + 1;
                } else if ((i % 2 == 0 && jaduArr[j] == 2) || (i % 2 == 1 && jaduArr[j] == 1)) {
                    dp[i][j] = Math.max(dp[i][j - 1], dp[i - 1][j - 1] + 1);
                }
                result = Math.max(result, dp[i][j]);
            }
        }
        
        bw.write(Integer.toString(result));
        bw.flush();
        bw.close();
        br.close();
    }
}