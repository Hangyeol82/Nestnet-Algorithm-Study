import java.io.*;
import java.util.*;

public class BackTracking15655 {
    static int n, m;
    static int[] arr = new int[10];
    static boolean[] vis = new boolean[10];
    static StringBuilder sb = new StringBuilder();

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
        }
        Arrays.sort(arr, 0, n);
        back(0, 0);

        System.out.println(sb);
    }

    public static void back(int k, int index) {
        if (k == m) {
            for (int i = 0; i < n; i++) {
                if (vis[i]) {
                    sb.append(arr[i]).append(" ");
                }
            }
            sb.append("\n");
            return;
        }

        for (int i = index; i < n; i++) {
            if (!vis[i]) {
                vis[i] = true;
                back(k + 1, i);
                vis[i] = false;
            }
        }
    }
}
