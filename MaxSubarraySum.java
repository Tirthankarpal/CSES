import java.util.*;
public class MaxSubarraySum {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int[] arr=new int[n];
        long res=Integer.MIN_VALUE;
        long sum=0;
        int max=Integer.MIN_VALUE;
        for(int i=0;i<n;i++){
            arr[i]=sc.nextInt();
        }
        for(int i=0;i<n;i++){
            max=Math.max(max,arr[i]);
            sum+=arr[i];
            sum=Math.max(0,sum);
            if(sum>0)res=Math.max(sum,res);
        }
        System.out.println(Math.max(max,res));
    }
}
