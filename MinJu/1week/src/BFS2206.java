import java.io.*;
import java.util.*;

public class BFS2206 {

    static int[][] map = new int[1005][1005];
    static int n, m;
    static int[][][] dist = new int[1005][1005][2];  //지나오는 경로 저장
    static boolean[][][] visited = new boolean[1005][1005][2];  //지나오면서 벽을 부순 적이 있는 경우, 없는 경우
    static int[] dx = {1, 0, -1, 0};
    static int[] dy = {0, 1, 0, -1};

    //queue는 순서대로 데이터를 저장하기 때문에 가장 먼저 n,m에 도달한 경우가 최단 경로가 된다.
    static Queue<int[]> queue = new LinkedList<>();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        //0, 0에서 n-1, m-1까지 이동하는 최단 경로
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        for (int i = 0; i < n; i++) {
            char[] amap = br.readLine().toCharArray();
            for (int j = 0; j < m; j++) {
                map[i][j] = amap[j] - '0';
            }
        }
        queue.add(new int[]{0, 0, 0});
        visited[0][0][0] = true;
        dist[0][0][0] = 1;

        while (!queue.isEmpty()) {
            int[] now = queue.poll();

            if (now[0] == n - 1 && now[1] == m - 1) {  //도착
                System.out.println(dist[now[0]][now[1]][now[2]]);
                return;
            }

            for (int i = 0; i < 4; i++) {
                int nx = now[0] + dx[i];
                int ny = now[1] + dy[i];

                if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;  //범위 밖

                if (now[2] == 0) {  //벽을 부순 적이 없는 경우  : 벽을 안 부수는 경우, 부수는 경우로 분기
                    for (int j = 0; j < 2; j++) {
                        if (visited[nx][ny][j]) continue;
                        if (map[nx][ny] == 1 && j == 0) continue;  //벽을 부수지 않는 경우

                        queue.add(new int[]{nx, ny, j});
                        visited[nx][ny][j] = true;
                        dist[nx][ny][j] = dist[now[0]][now[1]][0] + 1;
                    }

                } else {  //벽을 부순 적이 있는 경우 : 부수면 안됨
                    if (visited[nx][ny][1] || map[nx][ny] == 1) continue;

                    queue.add(new int[]{nx, ny, 1});
                    visited[nx][ny][1] = true;
                    dist[nx][ny][1] = dist[now[0]][now[1]][1] + 1;
                }
            }
        }

        System.out.println(-1);
    }
}
