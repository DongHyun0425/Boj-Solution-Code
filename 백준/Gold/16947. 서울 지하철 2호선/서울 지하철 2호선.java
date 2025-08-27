import java.io.*;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
    class Pair{
        int pos;
        int cnt;

        public Pair(int pos, int cnt) {
            this.pos = pos;
            this.cnt = cnt;
        }
    }

    int N=0;
    boolean flag = false;

    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    ArrayList<Integer>[] map = new ArrayList[3001];
    boolean cycle[] = new boolean[3001];
    boolean visited[] = new boolean[3001];

    void init() throws IOException{
        N= Integer.parseInt(br.readLine());
        for(int i=0;i<3001;i++){
            map[i] = new ArrayList<>();
         }

        for(int i=0;i<N;i++){
            StringTokenizer st = new StringTokenizer(br.readLine());

            int a = Integer.parseInt(st.nextToken());
            int b= Integer.parseInt(st.nextToken());

            map[a].add(b);
            map[b].add(a);
        }
    }

    void check_cycle(int x, int start, int prev){
        visited[x] = true;
        for(int i=0;i<map[x].size();i++){
            if(!visited[map[x].get(i)]){
                check_cycle(map[x].get(i), start, x);
            }else if(map[x].get(i) == start && map[x].get(i) !=prev){
                flag = true;
            }
        }
    }

    int find_cnt(int x){
        Queue<Pair> queue = new LinkedList<>();
        queue.add(new Pair(x, 0));
        visited[x] = true;
        while(!queue.isEmpty()){
            Pair p = queue.poll();
            int current = p.pos;
            int cnt = p.cnt;

            for(int i=0;i<map[current].size();i++){
                int next = map[current].get(i);

                //만약 다음이 사이클이라면
                if(cycle[next]){
                    return cnt+1;
                }
                if(!visited[next]){
                    visited[next]= true;
                    queue.add(new Pair(next, cnt+1));
                }
            }
        }
        return 0;
    }

    void solve()throws IOException{
        //step1: 각 노드가 cycle에 포함되는지 아닌지 확인
        for(int i=1;i<=N;i++){
            Arrays.fill(visited,false);
            flag = false;
            check_cycle(i,i,i);
            if(flag) cycle[i] = true;
        }

        //step2: 사이클에 포함된건 0 아니면 queued에 넣어서출력
        //왜 dfs가 아닌가?  3 - 4 - 5 -6 -7 인데 3과 7이 사이클이 있다 치자, 4에서 만약 5로 가버리는경우 7로가서 3이나옴
        //이걸 quque에 담아줘야함
        for(int i=1;i<=N;i++){
            if(cycle[i]){
                System.out.print(0 + " ");
            }else{
                Arrays.fill(visited,false);
                System.out.print(find_cnt(i) + " ");
            }
        }
    
    }


    public static void main(String[] args) throws Exception {
        Main m = new Main();   // Main 클래스 객체 생성
        m.init();
        m.solve();
    }
}
