import java.io.*;
import java.util.*;

public class BFS5014 {
    static int[] building = new int[1000005];  //몇 번 만에 갈 수 있는지
    static boolean[] visited = new boolean[1000005];
    static Queue<Integer> queue = new LinkedList<>();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int f = Integer.parseInt(st.nextToken());  //꼭대기층
        int s = Integer.parseInt(st.nextToken());  //현재층
        int g = Integer.parseInt(st.nextToken());  //도착층

        int[] ud = new int[2];
        ud[0] = Integer.parseInt(st.nextToken());  //위로 갈 수 있는 층수
        ud[1] = Integer.parseInt(st.nextToken());  //아래로 갈 수 있는 층수

        queue.add(s);
        building[s] = 0;
        visited[s] = true;

        if (s == g) {
            System.out.println(0);
            return;
        }

        while (!queue.isEmpty()) {
            int now = queue.poll();  //현재 층
            for (int i = 0; i < 2; i++) {  //위나 아래
                if (i == 0) {  //윗층
                    if (now + ud[i] > f) continue;  //범위 밖
                    if (visited[now + ud[i]]) continue;  //방문한 적 있는 경우

                    visited[now + ud[i]] = true;
                    building[now + ud[i]] = building[now] + 1;
                    if (now + ud[i] == g) {  // 도착
                        System.out.println(building[g]);
                        return;
                    }
                    queue.add(now + ud[i]);
                } else {  //아랫층
                    if (now - ud[i] < 1) continue;  //범위 밖
                    if (visited[now - ud[i]]) continue;  //방문한 적 있는 경우

                    visited[now - ud[i]] = true;
                    building[now - ud[i]] = building[now] + 1;
                    if (now - ud[i] == g) {  // 도착
                        System.out.println(building[g]);
                        return;
                    }
                    queue.add(now - ud[i]);
                }
            }
        }
        System.out.println("use the stairs");
    }
}