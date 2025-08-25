import java.io.*;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
    public class Node {
        int x;
        int y;
        int cnt;
        boolean wound; // 변수명은 보통 소문자로 시작

        // 생성자 추가
        public Node(int x, int y, int cnt, boolean wound) {
            this.x = x;
            this.y = y;
            this.cnt = cnt;
            this.wound = wound;
        }


    }

    int N,M,Ex,Ey,Hx,Hy=0;
    int Answer = 1000000;

    boolean visited[][][] = new boolean[1002][1002][2];
    int [][]map = new int[1002][1002];
    int dx[] = {0,0,1,-1};
    int dy[] = {1,-1,0,0};

    Queue<Node> queue = new LinkedList<>();

    void init() throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        st = new StringTokenizer(br.readLine());

        Ex = Integer.parseInt(st.nextToken());
        Ey = Integer.parseInt(st.nextToken());

        st = new StringTokenizer(br.readLine());

        Hx = Integer.parseInt(st.nextToken());
        Hy = Integer.parseInt(st.nextToken());

        for(int i=1;i<=N;i++){
            st = new StringTokenizer(br.readLine());
            for(int j=1;j<=M;j++){
                map[i][j] = Integer.parseInt(st.nextToken());
            }
        }

    }

    void solve(){
        Node node1 = new Node(Ex,Ey,0,false);
        queue.add(node1);
        visited[Ex][Ey][0]=true;
        visited[Ex][Ey][1]=true;

        while(!queue.isEmpty()){
            Node node = queue.poll();
            int x = node.x;
            int y = node.y;
            int cnt = node.cnt;
            boolean wound = node.wound;

            if(x==Hx && y==Hy && cnt<Answer){
                Answer = cnt;
                break;
            }

            for(int i=0;i<4;i++){
                int nx = x+dx[i];
                int ny = y+dy[i];

                if(nx<1 || nx>N || ny<1 || ny>M) continue;
                
                //case 1 벽이 아닌경우
                if(map[nx][ny]==0){
                    //지팡이 사용했는경우
                    if(wound && visited[nx][ny][1] == false) {
                        visited[nx][ny][1] = true;
                        queue.add(new Node(nx,ny,cnt+1,wound));
                    }else if(wound == false && visited[nx][ny][0]==false){
                        //지팡이 안사용했는경우
                        visited[nx][ny][0] = true;
                        queue.add(new Node(nx,ny,cnt+1,wound));
                    }
                }

                //case 2 벽인데 지팡이 사용안 안했는경우
                if(map[nx][ny] == 1 && wound == false && visited[nx][ny][1]==false){
                    visited[nx][ny][1]=true;
                    queue.add(new Node(nx,ny,cnt+1,true));
                }
            }
        }

        if(Answer == 1000000 ){
            System.out.println(-1);
        }else{
            System.out.println(Answer);
        }
    }

    public static void main(String[] args) throws Exception {
        Main m = new Main();   // Main 클래스 객체 생성
        m.init();
        m.solve();
    }
}
