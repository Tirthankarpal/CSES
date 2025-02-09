import java.util.*;
public class IncreasingArray {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int[] arr=new int[n];
        int sum=0;
        for(int i=0;i<n;i++){
            arr[i]=sc.nextInt();

        }
        long res=0;
        for(int i=1;i<n;i++){
            int num=Math.max(0,arr[i-1]-arr[i]);
            res+=(long)num;
            arr[i]+=num;
        }
        System.out.println(res);
    }
}
