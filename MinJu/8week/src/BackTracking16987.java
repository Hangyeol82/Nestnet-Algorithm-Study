import java.io.*;
import java.util.*;

public class BackTracking16987 {
    static int n;
    static int[] s = new int[10];  //내구도
    static int[] w = new int[10];  //무게
    static int[] brokenS = new int[10];  //깨진 내구도
    static int maxCnt=0;

    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());  // 계란 개수
        StringTokenizer st;

        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            s[i] = Integer.parseInt(st.nextToken());
            w[i] = Integer.parseInt(st.nextToken());
            brokenS[i] = s[i];
        }

        back(0);  //손에 들고있는 계란

        System.out.println(maxCnt);
    }

    public static void back(int egg) {
        if(egg==n){  //최근 든 계란이 가장 마지막 계란
            int cnt=0;
            for (int i = 0; i < n; i++) {
                if(brokenS[i]<=0) cnt++;
            }
            maxCnt = Math.max(cnt, maxCnt);
            return;
        }

        if (brokenS[egg] <= 0) { //손에 든 계란이 깨졋으면 치지않고 넘어간다.
            back(egg+1);
            return;
        }

        boolean isHit=false;
        for (int i = 0; i < n; i++) {
            if(brokenS[i]>0 && egg!=i){  //깨지지않은 계란을 친다.
                brokenS[i]-=w[egg];
                brokenS[egg] -= w[i];
                back(egg+1);
                isHit=true;
                brokenS[i]+=w[egg];
                brokenS[egg] += w[i];
            }
        }

        if(!isHit){ //깨지지 않은 계란이 없으면 치지않고 넘어간다.
            back(egg + 1);
        }
    }
}
