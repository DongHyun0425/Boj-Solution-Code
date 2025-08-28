import java.io.*;
import java.util.*;

public class Main {

    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    int T=0;
    PriorityQueue<Integer> pq_Max = new PriorityQueue<>(Comparator.reverseOrder());
    PriorityQueue<Integer> pq_Min = new PriorityQueue<>();
    HashMap<Integer,Integer> map = new HashMap<>();

    void init() throws IOException{
        T = Integer.parseInt(br.readLine());
    }

    void solve() throws IOException{
        for(int i=0;i<T;i++){
            int k = Integer.parseInt(br.readLine());
            pq_Max.clear();
            pq_Min.clear();
            map.clear();
            for(int j=0;j<k;j++){
                StringTokenizer st = new StringTokenizer(br.readLine());
                String s1 = st.nextToken();
                Integer I = Integer.parseInt(st.nextToken());

                //step 1: I로 넣는경우
                if(s1.equals("I")){
                    pq_Max.add(I);
                    pq_Min.add(I);
                    if(map.containsKey(I)){
                        map.put(I, map.get(I)+1);
                    }else{
                        map.put(I, 1);
                    }
                }

                //step 2: D 1 인경우
                if(s1.equals("D") && I == 1){
                    while(!pq_Max.isEmpty()){
                        //꺼내고 Array값 확인
                        int temp = pq_Max.poll();
                        if(map.containsKey(temp) && map.get(temp)>0){
                            map.put(temp, map.get(temp)-1);
                            break;
                        }
                    }
                }

                //step 3: D -1 인경우
                if(s1.equals("D") && I == -1){
                    while(!pq_Min.isEmpty()){
                        //꺼내고 Array값 확인
                        int temp = pq_Min.poll();
                        if(map.containsKey(temp) && map.get(temp)>0){
                            map.put(temp, map.get(temp)-1);
                            break;
                        }
                    }
                }
            }
            //step 4: 값 확인
                //최대값확인
                boolean Max_flag = false;
                int Max =0;
                while(!pq_Max.isEmpty()){
                    int temp = pq_Max.poll();
                    if(map.get(temp)>0){
                        Max = temp;
                        Max_flag = true;
                        break;
                    }
                }

                boolean Min_flag = false;
                int Min =0;
                while(!pq_Min.isEmpty()){
                    int temp = pq_Min.poll();
                    if(map.get(temp)>0){
                        Min = temp;
                        Min_flag = true;
                        break;
                    }
                }

                if(!Min_flag || !Max_flag){
                    System.out.println("EMPTY");
                }else{
                    System.out.println(Max + " " + Min);
                }
        }
    }


    public static void main(String[] args) throws Exception {
        Main m = new Main();   // Main 클래스 객체 생성
        m.init();
        m.solve();
    }
}
