import java.io.*;
import java.util.*;

public class Main {
    int N=0;
    int mid =0;

    int arr[] = new int[100001];
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    PriorityQueue<Integer> pq_Max = new PriorityQueue<>(Comparator.reverseOrder());
    PriorityQueue<Integer> pq_Min = new PriorityQueue<>();

    void init() throws IOException{
        N = Integer.parseInt(br.readLine());
    }

    void solve()throws IOException{
        for(int i=0;i<N;i++){
            int temp = Integer.parseInt(br.readLine());

            if(i==0){
                mid = temp;
                pq_Max.add(mid);    
            }else{
                //step 1: 일단 넣기
                if(mid<temp){
                    //중간값보다 큰경우는 min에다가 넣기
                    pq_Min.add(temp);
                }else{
                    //중간값 이하인 경우 Max에다가 넣기
                    pq_Max.add(temp);
                }

                //step 2: size비교
                //Max가 더큰경우
                if(pq_Max.size()>pq_Min.size() && Math.abs(pq_Max.size()-pq_Min.size())>1){
                    pq_Min.add(pq_Max.poll());
                }else if(pq_Max.size()<pq_Min.size()){
                    pq_Max.add(pq_Min.poll());
                }
            }
            //step3: mid출력후 갱신
            mid = pq_Max.peek();
            arr[i]=mid;
        }

        //step4: 출력
        for (int idx = 0; idx < N; idx++) {
            System.out.println(arr[idx]);   
        }
    }


    public static void main(String[] args) throws Exception {
        Main m = new Main();   // Main 클래스 객체 생성
        m.init();
        m.solve();
    }
}
