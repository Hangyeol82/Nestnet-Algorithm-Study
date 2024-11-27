import java.util.*;
import java.io.*;

public class BFS9466 {
    static int[] student = new int[1000005];  //팀을 같이 하고싶은 학생 저장
    static boolean[] vis = new boolean[1000005]; //팀 매칭 성공이든 실패든 이미 방문한 사람들
    static Queue<Integer> nowTeam = new LinkedList<>(); //현재 팀 구성에 포함되어있는 사람들 확인
    static int[] nowTeamOrd = new int[1000005];   //현재 팀 구성에 포함되어있는 사람들 지목 순서 확인

    public static void main(String[] args) throws IOException {
        StringBuilder sb = new StringBuilder();
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        StringTokenizer st;

        for (int i = 0; i < t; i++) {
            int n = Integer.parseInt(br.readLine());  //학생 수
            st = new StringTokenizer(br.readLine());
            for (int p = 1; p <= n; p++) {  // 팀 선택 저장
                student[p] = Integer.parseInt(st.nextToken());
            }
            int cnt = 0;
            for (int v = 1; v <= n; v++) {  //visit 배열 초기화
                vis[v] = false;
            }

            for (int s = 1; s <= n; s++) {
                if (vis[s]) continue;

                int stu = s;
                //처음과 끝이 같아야 한다.
                //혼자하고싶은 사람이나 다른 팀에 속해있는 사람을 선택하면 팀 성사가 안됨
                nowTeam.add(stu);
                vis[stu] = true;
                nowTeamOrd[stu] = nowTeam.size();

                while (true) {
                    int now = student[stu];  //stu: 지목한 학생, now: 지목당한 학생

                    if (stu == now) {  //혼자 하고싶은 사람
                        vis[now] = true;
                        cnt += nowTeam.size() - 1; //팀에 속하지 않는 학생 수 저장
                        break;
                    }

                    if (nowTeamOrd[now] != 0) {//팀 성사
                        cnt += nowTeamOrd[now] - 1;
                        break;
                    }

                    if (vis[now]) {  //다른 팀에 속해있는 사람
                        cnt += nowTeam.size();
                        break;
                    }

                    //지목 성공
                    vis[now] = true;
                    nowTeam.add(now);
                    nowTeamOrd[now] = nowTeam.size();
                    stu = now;
                }

                while (!nowTeam.isEmpty()) {
                    int pop = nowTeam.poll();
                    nowTeamOrd[pop] = 0;
                }

            }

            sb.append(cnt).append("\n");
        }

        System.out.println(sb);
    }
}
