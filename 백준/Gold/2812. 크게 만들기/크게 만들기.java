import java.io.*;
import java.util.Stack;
import java.util.StringTokenizer;

public class Main {
    int N=0;
    int K=0;
    String Num = "";
    Stack<Integer> stack = new Stack<>();
    
    void init() throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());

        Num = br.readLine();

    }

    void solve(){
        for(int i=0;i<N;i++){
            int n = Num.charAt(i)-'0';

            while(K>0 && stack.size()>0){
                if(stack.peek()<n){
                    stack.pop();
                    K--;
                }else{
                    break;
                }
            }
            stack.push(n);
        }

        //k가 남는경우
        while(K>0 && stack.size()>0){
            K--;
            stack.pop();
        }
    }

    void Answer(){
        if(stack.size()>0){
            for(int i=0;i<stack.size();i++){
                System.out.print(stack.get(i));
            }
        }else{
            System.out.print(0);
        }
    }

    public static void main(String[] args) throws Exception {
        Main m = new Main();   // Main 클래스 객체 생성
        m.init();
        m.solve();
        m.Answer();
    }
}
