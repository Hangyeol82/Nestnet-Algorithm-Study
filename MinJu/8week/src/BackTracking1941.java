import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;

public class BackTracking1941 {
    static char[][] map = new char[5][5];  //교실 자리 배치
    static boolean[][] member = new boolean[5][5];  // 칠공주 구성원 저장
    static int lee = 0; //이다솜파 학생들의 수
    static int cnt = 0; //경우의 수

    static int[] dx = {1, 0, -1, 0};
    static int[] dy = {0, 1, 0, -1};
    static Queue<int[]> queue = new LinkedList<>();
    static boolean[][] vis= new boolean[5][5];

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        for (int i = 0; i < 5; i++) {
            char[] arr = br.readLine().toCharArray();
            for (int j = 0; j < 5; j++) {
                map[i][j] = arr[j];
            }
        }

        func(0, 0, 0);

        System.out.println(cnt);
    }

    public static void func(int r, int c, int k) {
        if (k == 7) {
            if (lee >= 4 && bfs()) {
                cnt++;
            }
            return;
        }

        int j=c;
        //7명을 뽑는 조합 생성
        for (int i = r; i < 5; i++) {
            while(j<5){
                if(map[i][j]=='S') lee++;
                member[i][j]=true;

                if(j+1==5){
                    func(i + 1, 0, k +1);
                }else{
                    func(i, j + 1, k + 1);
                }

                if(map[i][j]=='S') lee--;
                member[i][j]=false;

                j++;
            }
            j=0;
        }
    }

    public static boolean bfs() {
        int memcnt=0;
        boolean addQ= false;
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                vis[i][j]=true;
                if(member[i][j]){
//                    vis[i][j]=true;
                    queue.add(new int[]{i, j});
                    memcnt++;
                    addQ=true;
                    break;
                }
            }
            if(addQ) break;
        }

        while (!queue.isEmpty()) {
            int[] now = queue.poll();
            for (int i = 0; i < 4; i++) {
                int nx = now[0] + dx[i];
                int ny = now[1] + dy[i];

                if(nx<0|| nx>=5|| ny<0|| ny>=5) continue;
                if(vis[nx][ny]) continue;

                vis[nx][ny]=true;
                if(member[nx][ny]){
                    memcnt++;
                    queue.add(new int[]{nx, ny});
                }
            }
        }
        for (int i = 0; i < 5; i++) {
            Arrays.fill(vis[i], false);
        }

        if(memcnt==7) return true;

        return false;
    }
}
