import java.io.*;
import java.util.*;

public class BFS2468 {

    static int[][] area = new int[105][105];  //어떤 지역의 높이 정보
    static int minRain = 100;
    static int maxRain = 2;  //비의 양 범위
    static int length;
    static int max = 1;  //안전 영역의 최대 개수
    static boolean[][] visited = new boolean[105][105];  //안전영역 순회
    static Queue<int[]> queue = new LinkedList<>();
    static int[] dx = {1, 0, -1, 0};
    static int[] dy = {0, 1, 0, -1};
    static int n;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());  //지역 범위
        StringTokenizer st;
        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < n; j++) {
                area[i][j] = Integer.parseInt(st.nextToken());
                if (area[i][j]<minRain) minRain=area[i][j];
                if(area[i][j]>maxRain) maxRain = area[i][j];
            }
        }

        //비의 양에 따른 안전영역 개수 구하기
        for (length = minRain; length <= maxRain; length++) {
            int safe=0;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if(!visited[i][j] && area[i][j]>length){
                        queue.add(new int[]{i, j});
                        visited[i][j]=true;
                        bfs();
                        safe++;
                    }
                }
            }

            if(safe>max) max=safe;
            //상태 초기화
            while(!queue.isEmpty()){
                queue.poll();
            }
            for (int i = 0; i < n; i++) {
                Arrays.fill(visited[i], false);
            }
        }

        System.out.println(max);
    }

    public static void bfs() {
        while (!queue.isEmpty()) {
            int[] now = queue.poll();

            for (int i = 0; i < 4; i++) {  //주변지역 점검
                int nx = now[0] + dx[i];
                int ny = now[1] + dy[i];
                if(nx<0|| nx>=n||ny<0|| ny>=n ) continue;  //범위 밖
                if(visited[nx][ny]|| area[nx][ny]<=length) continue;

                queue.add(new int[]{nx, ny});
                visited[nx][ny]=true;
            }
        }
    }
}
