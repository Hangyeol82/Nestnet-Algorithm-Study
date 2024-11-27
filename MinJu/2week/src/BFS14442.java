import java.util.*;
import java.io.*;

public class BFS14442 {

    static int[] dx = {1, 0, -1, 0};
    static int[] dy = {0, 1, 0, -1};
    static int[][] map = new int[1005][1005];
    static int[][][] path = new int[1005][1005][15];  //경로 상 최단 거리 저장 {거리, 벽 부순 개수}
    static Queue<int[]> queue = new LinkedList<>();  // {경로 상 x좌표, y좌표, 벽을 몇 개 부쉈는지}

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());  //벽을 k개까지 부수고 이동해도 된다.

        for (int i = 0; i < n; i++) {  //map 초기화
            char[] maps = br.readLine().toCharArray();
            for (int j = 0; j < m; j++) {
                map[i][j] = maps[j] - '0';
            }
        }
        //(0,0) ~ (n-1, m-1) 최단거리 출력
        queue.add(new int[]{0, 0, 0});
        path[0][0][0] = 1;

        while (!queue.isEmpty()) {
            int[] now = queue.poll();
            int x = now[0];
            int y = now[1];
            int broken = now[2];

            if (now[0] == n - 1 && now[1] == m - 1) {  //종료조건
                System.out.println(path[now[0]][now[1]][now[2]]);
                return;
            }

            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;  //map 범위

                if (map[nx][ny] == 1 && path[nx][ny][broken + 1] == 0) {  //벽 부수고 진행
                    if (broken >= k) continue;  //벽을 k개까지만 부술 수 있다.
                    queue.add(new int[]{nx, ny, broken + 1});
                    path[nx][ny][broken + 1] = path[x][y][broken] + 1;  //거리 저장
                }

                if (map[nx][ny] == 0 && path[nx][ny][broken] == 0) {  //안부수고 진행
                    queue.add(new int[]{nx, ny, broken});
                    path[nx][ny][broken] = path[x][y][broken] + 1;  //거리 저장
                }
            }
        }

        System.out.println(-1);
    }
}
